// https://www.acmicpc.net/problem/22865
// 2024-05-30 01:41:08
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
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
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    vector<int> friends(3);
    for(int i=0; i<3; i++)
        cin >> friends[i];

    int m; cin >> m;
    vector<vector<pair<int, int> > > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vector<dijkstra> dijk;
    for(int i=0; i<3; i++)
        dijk.push_back(dijkstra(friends[i], graph));
    
    int ans_dist=0, ans=0;
    for(int i=1; i<=n; i++)
    {
        int tmp=min({dijk[0].dist[i], dijk[1].dist[i], dijk[2].dist[i]});
        if(ans_dist < tmp)
            ans_dist=tmp, ans=i;
    }
    cout << ans;
}

/*
    
*/