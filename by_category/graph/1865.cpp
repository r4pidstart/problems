// https://www.acmicpc.net/problem/1865
// 2022-06-07 00:18:48 520ms
#include"bits/stdc++.h"
using namespace std;

class Floyd
{
    // adjacent matrix 1~n, O(V^3)
    public:
        vector<vector<int> > dist;
        Floyd(const vector<vector<int> >& graph)
        {
            dist=graph;
            for(int i=1; i<dist.size(); i++)
                for(int j=1; j<dist.size(); j++)
                    for(int k=1; k<dist.size(); k++)
                    {
                        dist[j][k]=min(dist[j][k], dist[j][i]+dist[i][k]);
                        if(dist[j][j] < 0)
                        {
                            printf("YES\n");
                            return;
                        }
                    }
            printf("NO\n");
        }
};

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n, m, w; scanf("%d%d%d", &n, &m, &w);
        vector<vector<int> > graph(n+1, vector<int>(n+1, INT32_MAX/2));
        for(int i=1; i<=n; i++)
            graph[i][i]=0;

        for(int i=0; i<m; i++)
        {
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            graph[a][b]=min(c, graph[a][b]);
            graph[b][a]=min(c, graph[b][a]);
        }
        for(int i=0; i<w; i++)
        {
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            graph[a][b]=min(-c, graph[a][b]);
        }

        Floyd floyd(graph);
    }
}

/*
    
*/