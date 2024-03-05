// https://www.acmicpc.net/problem/31414
// 2024-03-04 21:30:52
#include"bits/stdc++.h"
using namespace std;

int bipartite(int now, int c, const vector<vector<int> >& graph, vector<int>& color)
{
    if(color[now]!=-1)
        return 0;
    color[now]=c;
    for(int next : graph[now])
        bipartite(next, c^1, graph, color);
    return 0;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        graph[i+1].push_back(a);
        graph[a].push_back(i+1);
    }
    for(int i=1; i<=n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
        graph[i].resize(unique(graph[i].begin(), graph[i].end())-graph[i].begin());
    }

    vector<int> color(n+1, -1);
    for(int i=1; i<=n; i++)
        if(color[i]==-1)
            bipartite(i, 0, graph, color);

    vector<int> visited(n+1);
    int c1=0, c2=0;
    for(int i=1; i<=n; i++)
    {
        for(int next : graph[i])
        {
            if(color[i]==0)
            {
                // 0에 놓는다고 가정했을 때
                if(color[next]==1) c1++;
            }
            else 
            {
                // 1에 놓는다고 가정했을 때
                if(color[next]==0) c2++;
            }
        }
            
    }

    printf("%d", max(c1, c2));
}

/*
    
*/