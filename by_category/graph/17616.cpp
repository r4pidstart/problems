// https://www.acmicpc.net/problem/17616
// 2024-03-18 00:44:59
#include"bits/stdc++.h"
using namespace std;

int dfs(int now, const vector<vector<int> >& graph, vector<int>& chk)
{
    chk[now]=1;
    for(int next : graph[now])
        if(!chk[next])
            dfs(next, graph, chk);
    return 0;
}

int main(void)
{
    int n,m,x; scanf("%d%d%d", &n, &m, &x);
    vector<vector<int> > graph(n+1), graph_r(n+1);

    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph_r[b].push_back(a);
    }

    vector<int> after_x(n+1), before_x(n+1);
    
    dfs(x, graph, after_x);
    dfs(x, graph_r, before_x);

#ifdef LOCAL
    for(int i : after_x)
        printf("%d ", i);
    printf("\n");
    for(int i : before_x)
        printf("%d ", i);
    printf("\n");
#endif
    printf("%d %d", accumulate(before_x.begin(), before_x.end(), 0), n+1-accumulate(after_x.begin(), after_x.end(), 0));
}

/*
    
*/