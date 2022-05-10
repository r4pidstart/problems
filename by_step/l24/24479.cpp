// https://www.acmicpc.net/problem/24479
// 2022-05-11 04:31:44 128ms
#include"bits/stdc++.h"
using namespace std;

void dfs(int now, int prev, vector<int>& order, const vector<vector<int> >& graph)
{
    static int cnt=0;
    if(order[now]) return;
    order[now]=++cnt;

    for(auto next : graph[now])
        if(next != prev) dfs(next, now, order, graph);
}

int main(void)
{
    int n,m,r; scanf("%d%d%d", &n, &m, &r);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(auto& it : graph)
        sort(it.begin(), it.end());

    vector<int> order(n+1, 0);
    dfs(r, -1, order, graph);
    for(int i=1; i<=n; i++)
        printf("%d\n", order[i]);
}

/*
    
*/