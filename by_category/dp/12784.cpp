// https://www.acmicpc.net/problem/12784
// 2023-12-27 02:56:49
#include"bits/stdc++.h"
using namespace std;

int ans(int now, int prev, const vector<vector<pair<int,int> > >& graph, int init=0)
{
    static vector<int> memo;
    if(init) memo=vector<int>(graph.size(), -1);
    if(memo[now] != -1) return memo[now];
    if(graph[now].size() == 1 and prev != -1) return graph[now][0].second;

    int ret=0;
    for(auto [next, cost] : graph[now])
        if(next != prev)
            ret+=min(cost, ans(next, now, graph));

    return memo[now]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m; scanf("%d%d", &n, &m);
        vector<vector<pair<int, int> > > graph(n+1);
        for(int i=0; i<m; i++)
        {
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
        printf("%d\n", ans(1, -1, graph, 1));
    }
}

/*
    
*/