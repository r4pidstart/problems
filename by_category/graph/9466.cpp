// https://www.acmicpc.net/problem/9466
// 2022-07-31 10:39:16
#include"bits/stdc++.h"
using namespace std;

int dfs(int now, int& cnt, vector<int>& graph, vector<int>& visited, vector<int>& used)
{
    visited[now]=1;

    if(!visited[graph[now]]) dfs(graph[now], cnt, graph, visited, used);
    else if(!used[graph[now]])
    {
        for(int i=graph[now]; i!=now; i=graph[i]) cnt++;
        cnt++;
    }

    used[now]=1;
    return 0;
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<int> graph(n);
        for(int i=0; i<n; i++)
            scanf("%d", &graph[i]), graph[i]--;
    
        int cnt=0;
        vector<int> used(n), visited(n);
        // find cycle
        for(int i=0; i<n; i++)
            dfs(i, cnt, graph, visited, used);
        printf("%d\n", n-cnt);
    }
}

/*
    
*/