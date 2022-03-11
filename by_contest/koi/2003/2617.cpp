// https://www.acmicpc.net/problem/2617
// 2022-03-12 02:47:08 0ms
#include<bits/stdc++.h>
using namespace std;

int dfs(int now, vector<vector<int> >& graph, int clear=0)
{
    static vector<int> visited;
    if(clear)
        visited.assign(clear, 0);

    visited[now]=1;

    int cnt=clear ? 0:1;
    for(int next : graph[now])
        if(!visited[next])
            cnt+=dfs(next, graph);
        
    return cnt;
}

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > heavy_graph(n+1), light_graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        heavy_graph[b].push_back(a);
        light_graph[a].push_back(b);
    }

    // 해당 구슬보다 가벼운 것의 갯수, 무거운 것의 갯수를 세서 n/2개보다 많으면 카운트
    int cnt=0;
    for(int i=1; i<=n; i++)
        if(dfs(i, heavy_graph, n+1) > n/2 or dfs(i, light_graph, n+1) > n/2)
            cnt++;
    printf("%d", cnt);
}

/*
    
*/