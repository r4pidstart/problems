// https://www.acmicpc.net/problem/2307
// 2022-05-29 00:52:09 92ms
#include"bits/stdc++.h"
using namespace std;

class dijkstra
{
    // graph[from]={to, cost}, O(ElogV)
    public:
        vector<int> dist;
        vector<pair<int,int> > prev;
        dijkstra(int start, const vector<vector<pair<int,int> > > &graph)
        {
            priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
            dist.assign(graph.size(), INT32_MAX/2);
            prev.assign(graph.size(), make_pair(-1, -1));
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
                        prev[next.first]={now, next.second};
                        pq.push({next_cost, next.first});
                    }
                }
            }
        }
};

int main(void)
{
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    auto min_time=dijkstra(1, graph);
    vector<vector<pair<int,int> > > used(n+1);
    int cur=n;
    while(cur != 1)
    {
        used[cur].push_back(min_time.prev[cur]);
        cur=min_time.prev[cur].first;
    }

    int ans=0;
    for(int i=1; i<=n; i++)
        for(auto it1 : used[i])
        {
            int tmp=it1.second;
            auto it2=find(graph[it1.first].begin(), graph[it1.first].end(), make_pair(i, tmp));
            it1.second=it2->second=INT32_MAX/2;
            ans = max(ans, dijkstra(1, graph).dist[n] - min_time.dist[n]);
            it1.second=it2->second=tmp;
        }
    
    if(ans == INT32_MAX/2 - min_time.dist[n])
        ans=-1;
    printf("%d", ans);
}

/*
    
*/