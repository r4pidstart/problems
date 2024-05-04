// https://www.acmicpc.net/problem/31556
// 2024-05-03 21:05:41
#include"bits/stdc++.h"
using namespace std;

int dfs(int now, int prev, const vector<vector<int> >& graph, multiset<int>& target)
{
    int ret=(now!=1 and graph[now].size()==1);
    for(int next : graph[now])
        if(next != prev)
            ret+=dfs(next, now, graph, target);
    
    auto it=target.lower_bound(now);
    while(it != target.end() and *it==now and ret)
    {
        it=target.erase(target.find(now));
        ret--;
    }
    return ret;
}

int count_route(int now, int prev, const vector<vector<int> >& graph)
{
    if(now!=1 and graph[now].size()==1)
        return 1;

    int ret=0;
    for(int next : graph[now])
        if(next != prev)
            ret+=count_route(next, now, graph);

    return ret;
}

int main(void)
{
    int n; scanf("%d", &n);

    if(n==1)
        return !printf("1");
    
    vector<vector<int> > graph(n+1);
    vector<int> seq(n);
    for(int i=0; i<n; i++)
        scanf("%d", &seq[i]);

    for(int i=0; i<n-1; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int cnt=count_route(1, -1, graph);

    multiset<int> target;
    for(int i=0; i<cnt; i++)
        target.insert(seq[i]);
    
    dfs(1, -1, graph, target);
    printf("%d", cnt-target.size());
}

/*
    n==1일때
*/