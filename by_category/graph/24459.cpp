// https://www.acmicpc.net/problem/24453
// 2022-11-18 01:44:47
#include"bits/stdc++.h"
using namespace std;

pair<int, int> dfs(int now, int prev, vector<vector<pair<int,int> > >& graph)
{
    static int minimum=INT32_MAX, maximum=0;

    if(prev!=-1 and graph[now].size() == 1) // leaf
        return {0,0};

    vector<int> cand1, cand2;
    for(auto next : graph[now])
        if(next.first != prev)
        {
            auto tmp=dfs(next.first, now, graph);
            cand1.push_back(tmp.first+next.second);
            cand2.push_back(tmp.second+next.second);
        }

    sort(cand1.begin(), cand1.end());
    sort(cand2.begin(), cand2.end(), greater<>());
    if(cand1.size()>=2)
        minimum=min(minimum, cand1[0]+cand1[1]);
    if(cand2.size()>=2)
        maximum=max(maximum, cand2[0]+cand2[1]);

    if(prev==-1)
        return {max(cand2.front(), maximum), min(cand1.front(), minimum)};
    return {cand1.front(), cand2.front()};
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=1; i<n; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    int leaf=-1;
    for(int i=0; i<n; i++)
        if(graph[i].size()==1) leaf=i;
    auto ans=dfs(leaf, -1, graph);
    printf("%d\n%d", ans.first, ans.second);
}

/*
    
*/