// https://www.acmicpc.net/problem/16168
// 2024-04-04 20:16:05
#include"bits/stdc++.h"
using namespace std;

int dfs(int now, vector<int>& visited, vector<vector<int> >& graph)
{
    visited[now]=1;

    int ret=1;
    for(auto next : graph[now])
        if(!visited[next])
            ret+=dfs(next, visited, graph);

    return ret;
}

int main(void)
{
    int v,e; scanf("%d%d", &v, &e);
    vector<vector<int> > graph(v+1);
    for(int i=0; i<e; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        assert(0<a and a<=v and 0<b and b<=v);
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
        // graph[a].push_back(b);
        // graph[b].push_back(a);
    }

    // 도달가능성 체크
    vector<int> visited(v+1);
    int reached=dfs(1, visited, graph);

    if(reached != v)
        return !printf("NO");

    int cnt=0;
    for(int i=0; i<v; i++)
    {
        if(graph[i].size()&1)
            cnt++;
    }
    printf(cnt==2 or !cnt ? "YES":"NO");
}

/*
    
*/