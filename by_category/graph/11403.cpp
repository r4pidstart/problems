// https://www.acmicpc.net/problem/11403
// 2022-03-15 23:55:09 4ms
#include<bits/stdc++.h>
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
                        dist[j][k]=min(dist[j][k], dist[j][i]+dist[i][k]);
        }
};

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > adj(n+1, vector<int>(n+1));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            scanf("%d", &adj[i+1][j+1]);
            if(adj[i+1][j+1] == 0)
                adj[i+1][j+1] = INT32_MAX/2;
        }
    
    Floyd floyd(adj);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            printf("%d ", floyd.dist[i][j] == INT32_MAX/2 ? 0 : 1);
        printf("\n");
    }
    
}

/*
    
*/