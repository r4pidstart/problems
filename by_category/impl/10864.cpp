// https://www.acmicpc.net/problem/10864
// 2023-04-30 00:56:06
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
        printf("%d\n", graph[i].size());
}

/*
    
*/