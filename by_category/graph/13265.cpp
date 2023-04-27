// https://www.acmicpc.net/problem/13265
// 2023-04-27 07:39:14
#include"bits/stdc++.h"
using namespace std;

int dfs(int now, vector<vector<int> >& graph, vector<int>& visited, int color=0)
{
    if(visited[now] != -1) return 0;
    visited[now]=color;
    for(int next : graph[now])
    {
        if(visited[next] == color) return 1;
        if(visited[next]==-1 and dfs(next, graph, visited, color^1)) return 1;
    }
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m; scanf("%d%d", &n, &m);
        vector<vector<int> > graph(n+1);
        for(int i=0; i<m; i++)
        {
            int a,b; scanf("%d%d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<int> visited(n+1, -1);
        int ret=0;
        for(int i=1; i<=n; i++) 
            ret+=dfs(i, graph, visited);
        printf(!ret ? "possible\n" : "impossible\n");
    }
}

/*
    
*/