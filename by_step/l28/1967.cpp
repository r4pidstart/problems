// https://www.acmicpc.net/problem/1967
// 2023-02-13 00:22:07
#include"bits/stdc++.h"
using namespace std;

pair<int,int> farthest(int now, vector<vector<pair<int, int> > >& graph, int begin)
{
    static vector<int> visited;

    if(begin)
        visited=vector<int>(graph.size());

    visited[now]=1;
    pair<int,int> ret={0, now};
    for(auto& [next, dist] : graph[now])
    {
        if(!visited[next])
        {
            auto tmp=farthest(next, graph, 0);
            if(tmp.first+dist > ret.first)
                ret={tmp.first+dist, tmp.second};
        }
    }
    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<vector<pair<int, int> > > graph(n+1);
    for(int i=0; i<n-1; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    printf("%d", farthest(farthest(1, graph, 1).second, graph, 1).first);
}

/*
    
*/