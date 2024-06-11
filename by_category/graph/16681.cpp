// https://www.acmicpc.net/problem/16681
// 2024-06-10 23:22:50
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

class dijkstra
{
    // graph[from]={to, cost}, O(ElogV)
    public:
        vector<long> dist;
        dijkstra(int start, const vector<vector<pair<int,int> > > &graph, const vector<int>& height)
        {
            priority_queue<pair<long, long>, vector<pair<long,long> >, greater<pair<long,long> > > pq;
            dist.assign(graph.size(), LONG_MAX/4);
            pq.push({0, start}), dist[start]=0;
            while(!pq.empty())
            {
                auto [total_cost, now]=pq.top(); pq.pop();
                if(dist[now] < total_cost) continue;
                for(auto next : graph[now])
                {
                    if(height[next.first] > height[now])
                    {
                        long next_cost=total_cost+next.second;
                        if(dist[next.first]>next_cost) 
                        {
                            dist[next.first]=next_cost;
                            pq.push({next_cost, next.first});
                        }
                    }
                }
            }
        }
};

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,m,d,e; cin >> n >> m >> d >> e;
    vector<int> height(n+1);
    for(int i=1; i<=n; i++)
        cin >> height[i];
    
    vector<vector<pair<int, int> > > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dijkstra dijk_from_1(1, graph, height), dijk_from_n(n, graph, height);

    long ans=LLONG_MIN;
    for(int i=1; i<=n; i++)
        if(dijk_from_1.dist[i] != LONG_MAX/4 and dijk_from_n.dist[i] != LONG_MAX/4)
            ans=max(ans, 1L*height[i]*e-(dijk_from_1.dist[i]+dijk_from_n.dist[i])*d);
    if(ans==LLONG_MIN)
        cout << "Impossible";
    else
        cout << ans;
}

/*
    
*/