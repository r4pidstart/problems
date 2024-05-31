// https://www.acmicpc.net/problem/13244
// 2024-05-31 16:07:32
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int dfs(int now, vector<int>& visited, const vector<vector<int> >& graph)
{
    visited[now]=1;

    int ret=0;
    for(auto next : graph[now])
        if(!visited[next])
            ret+=dfs(next, visited, graph);
    return ret+1;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int t; cin >> t;
    while(t--)
    {
        int n,m; cin >> n >> m;
        vector<vector<int> > graph(n+1);
        for(int i=0; i<m; i++)
        {
            int a,b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> visited(n+1);
        visited[1]=1;
        if(m!=n-1 or dfs(1, visited, graph) != n)
        {
            cout << "graph\n";
            continue;
        }
        cout << "tree\n";
    }
}

/*
    
*/