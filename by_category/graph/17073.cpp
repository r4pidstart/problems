// https://www.acmicpc.net/problem/17073
// 
#include"bits/stdc++.h"
using namespace std;

int dfs(int now, int prev, vector<vector<int> >& graph)
{
    if(now!=1 and graph[now].size()==1)
        return 1;

    int ret=0;
    for(int next : graph[now])
        if(next!=prev)
            ret+=dfs(next, now, graph);
    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,w; scanf("%d%d", &n, &w);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<n-1; i++)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    printf("%lf", (double)w/dfs(1, -1, graph));
}

/*
    
*/