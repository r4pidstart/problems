// https://www.acmicpc.net/problem/2665
// 2022-01-17 22:04:07 0ms 
#include<bits/stdc++.h>
using namespace std;

class dijkstra
{
    // graph[from]={to, cost}, O(ElogV)
    public:
        vector<int> dist;
        dijkstra(int start, const vector<vector<pair<int,int> > > &graph)
        {
            priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
            dist.assign(graph.size(), INT32_MAX/2);
            pq.push({0, start}), dist[start]=0;
            while(!pq.empty())
            {
                auto [total_cost, now]=pq.top(); pq.pop();
                if(dist[now] < total_cost) continue;
                for(auto next : graph[now])
                {
                    int next_cost=total_cost+next.second;
                    if(dist[next.first]>next_cost) 
                    {
                        dist[next.first]=next_cost;
                        pq.push({next_cost, next.first});
                    }
                }
            }
        }
};

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > table(n, vector<int>(n,0));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%1d", &table[i][j]);

    const int way[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<pair<int,int> > > graph(n*n+1);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int w=0; w<4; w++)
            {
                int nx=i+way[w][0], ny=j+way[w][1];
                if(0<=nx and nx<n and 0<=ny and ny<n)
                {
                    if(table[nx][ny]) graph[i*n + j + 1].push_back({nx*n + ny + 1, 0});
                    else graph[i*n + j + 1].push_back({nx*n + ny + 1, 1});
                }
            }
    
    dijkstra dijk(1, graph);
    printf("%d", dijk.dist[n*n]);
}

/*
    
*/