// https://www.acmicpc.net/problem/20924
// 2024-01-19 01:22:08
#include"bits/stdc++.h"
using namespace std;

pair<int,int> solution(int now, int prev, int after_giga, const vector<vector<pair<int, int> > >& graph)
{   
    if(graph[now].size() > 2 or (graph[now].size() > 1 and prev == -1))
        after_giga=1;

    int ret1=0, ret2=0;
    for(auto [next, ncost] : graph[now])
    {
        if(next == prev) continue;
        auto tmp=solution(next, now, after_giga, graph);
        ret1=max(ret1, ncost*!after_giga+tmp.first);
        ret2=max(ret2, ncost*after_giga+tmp.second);
    }
    return {ret1, ret2};
}

int main(void)
{
#ifdef LOCAL
#endif
    int n, r; scanf("%d%d", &n, &r);
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=1; i<n; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    auto ans=solution(r, -1, 0, graph);
    printf("%d %d", ans.first, ans.second);
}

/*
    
*/