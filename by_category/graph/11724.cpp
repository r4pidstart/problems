// https://www.acmicpc.net/problem/11724
// 2021-10-18 22:57:38 136ms
#include<bits/stdc++.h>
using namespace std;

int cnt=0;
vector<vector<int> > graph;
vector<int> visited;

void dfs(int now)
{
    if(visited[now]) return;
    visited[now]=1;
    for(auto& next : graph[now])
        if(!visited[next]) dfs(next);
}
int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    graph.assign(n+1,{});
    visited.assign(n+1,0);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
        if(!visited[i]) 
        {
            dfs(i);
            cnt++;
        }

    printf("%d", cnt);
}

/*
    
*/