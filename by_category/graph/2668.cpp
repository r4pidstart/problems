// https://www.acmicpc.net/problem/2668
// 2023-04-11 00:34:25
#include"bits/stdc++.h"
using namespace std;

int dfs(int now, int start, vector<int>& graph, set<int>& lst)
{
    static vector<int> visited(101, 0);

    if(now==start) return 1;
    visited[now]=1;

    int ret=0;
    if(!visited[graph[now]] and dfs(graph[now], start, graph, lst))
        ret++;
    visited[now]=0;
    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> graph(n+1);
    for(int i=1; i<=n; i++)
        scanf("%d", &graph[i]);

    set<int> lst;
    for(int i=1; i<=n; i++)
    {
        if(dfs(graph[i], i, graph, lst))
            lst.insert(graph[i]);
    }
    printf("%d\n", lst.size());
    for(auto i : lst)
        printf("%d\n", i);
}

/*
    
*/