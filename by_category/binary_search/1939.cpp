// https://www.acmicpc.net/problem/1939
// 2024-02-14 04:36:38
#include"bits/stdc++.h"
using namespace std;

int decision(int mid, const vector<vector<pair<int,int> > >& graph, int a, int b)
{
    vector<int> visited(graph.size());
    queue<int> q;
    q.push(a);
    visited[a]=1;
    while(q.size())
    {
        int now=q.front();
        q.pop();

        if(now==b)
            return 1;

        for(auto [next, limit] : graph[now])
        {
            if(limit >= mid and !visited[next])
                visited[next]=1, q.push(next);
        }
    }
    return 0;
}

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<pair<int, int> > > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int a,b; scanf("%d%d", &a, &b);
    int lo=0, hi=1e9, ans=0;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(mid, graph, a, b))
            lo=mid+1, ans=mid;
        else
            hi=mid-1;
    }
    printf("%d", ans);
}

/*
    
*/