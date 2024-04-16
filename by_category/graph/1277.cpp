// https://www.acmicpc.net/problem/1277
// 2024-04-09 00:04:44
#include"bits/stdc++.h"
using namespace std;

class dijkstra
{
    // graph[from]={to, cost}, O(ElogV)
    public:
        vector<double> dist;
        dijkstra(int start, const vector<vector<pair<int,double> > > &graph)
        {
            priority_queue<pair<double, double>, vector<pair<double,double> >, greater<pair<double,double> > > pq;
            dist.assign(graph.size(), INT32_MAX/2);
            pq.push({0, start}), dist[start]=0;
            while(!pq.empty())
            {
                auto [total_cost, now]=pq.top(); pq.pop();
                if(dist[now] < total_cost) continue;
                for(auto next : graph[now])
                {
                    double next_cost=total_cost+next.second;
                    if(dist[next.first]>next_cost) 
                    {
                        dist[next.first]=next_cost;
                        pq.push({next_cost, next.first});
                    }
                }
            }
        }
};

inline double get_dist(const pair<double, double>& a, const pair<double, double>& b)
{
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main(void)
{
    int n,w; scanf("%d%d", &n, &w);
    double maximum; scanf("%lf", &maximum);
    vector<vector<pair<int, double> > > graph(n);
    
    vector<pair<double, double> > points(n);
    for(int i=0; i<n; i++)
        scanf("%lf %lf", &points[i].first, &points[i].second);
    
    for(int i=0; i<w; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        a--, b--;
        graph[a].push_back({b, 0});
        graph[b].push_back({a, 0});
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i!=j and get_dist(points[i], points[j]) <= maximum)
                graph[i].push_back({j, get_dist(points[i], points[j])});

    dijkstra dijk(0, graph);
    printf("%d", int(dijk.dist[n-1]*1000));    
}

/*
    
*/