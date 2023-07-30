// https://www.acmicpc.net/problem/22856
// 2023-07-30 23:47:52
#include"bits/stdc++.h"
using namespace std;

int dfs(int now, int prev, vector<vector<int> >& graph)
{
    static int cnt=1;

    int ret=0;
    if(graph[now][0] != -1)
        ret+=dfs(graph[now][0], now, graph)+1;
    cnt++;
    if(graph[now][1] != -1)
        ret+=dfs(graph[now][1], now, graph)+1;

    if(cnt!=graph.size()) return ret+1;
    else return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<n; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back(b);
        graph[a].push_back(c);
    }
    printf("%d", dfs(1, 1, graph));
}

/*
    
*/