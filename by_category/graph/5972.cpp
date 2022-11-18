// https://www.acmicpc.net/problem/5972
// 2022-11-19 03:12:24
#include"bits/stdc++.h"
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
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    dijkstra dijk(1, graph);
    printf("%d", dijk.dist[n]);
}

/*
    
*/