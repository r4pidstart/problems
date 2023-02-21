// https://www.acmicpc.net/problem/14657
// 2023-02-19 20:22:44
#include"bits/stdc++.h"
using namespace std;

// depth, -dist, end_point
tuple<int,int,int> dfs(int now, int prev, vector<vector<pair<int, int> > >& graph)
{
    tuple<int,int,int> res={0,0,now};
    for(auto [next, dist] : graph[now])
    {
        if(next != prev)
        {
            auto [pdepth, pdist, pend]=dfs(next, now, graph);
            tuple<int,int,int> tmp={pdepth+1, pdist-dist, pend};
            res=max(res, tmp);
        }
    }
    return res;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n, t; scanf("%d%d", &n, &t);
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0; i<n-1; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int res=-get<1>(dfs(get<2>(dfs(1, 0, graph)), 0, graph));
    printf("%d", (res+t-1)/t);
}

/*
    
*/