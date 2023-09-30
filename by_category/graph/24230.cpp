// https://www.acmicpc.net/problem/24230
// 2023-09-29 22:42:41
#include"bits/stdc++.h"
using namespace std;

int dfs(int now, int prev, vector<vector<int> >& graph, vector<int>& color)
{
    if(now!=1 and graph[now].size()==1)
        return 0;
    
    int ret=0;
    for(int next : graph[now])
        if(next != prev)
        {
            if(color[next] != color[now]) ret++;
            ret+=dfs(next, now, graph, color);
        }

    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> color(n+1);
    for(int i=1; i<=n; i++)
        scanf("%d", &color[i]);
    
    vector<vector<int> > graph(n+1);
    for(int i=0; i<n-1; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    printf("%d", dfs(1, -1, graph, color)+(color[1]!=0));
}

/*
    
*/