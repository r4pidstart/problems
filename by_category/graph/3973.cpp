// https://www.acmicpc.net/problem/3973
// 2022-07-17 04:09:52
#include"bits/stdc++.h"
using namespace std;

pair<int,int> dfs(int now, int len, vector<vector<int> >& graph, vector<int>& visited)
{
    pair<int,int> ret={now,len};
    for(auto next : graph[now])
        if(!visited[next])
        {
            visited[next]=1;
            auto tmp=dfs(next, len+1, graph, visited);
            if(tmp.second > ret.second)
                ret=tmp;
        }
    return ret;
}

int diameter(vector<vector<int> >& graph)
{
    vector<int> visited(graph.size()+1);
    auto a=dfs(1, 0, graph, visited);

    visited.assign(graph.size()+1, 0);
    auto b=dfs(a.first, 0, graph, visited);
    
    return b.second;
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<vector<int> > graph(n);
        for(int i=1; i<n; i++)
        {
            int a,b; scanf("%d%d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        printf("%d\n", (diameter(graph)+1)/2);
    }
}

/*
    
*/