// https://www.acmicpc.net/problem/5719
// 2022-12-03 00:27:07
#include"bits/stdc++.h"
using namespace std;

class dijkstra
{
    // graph[from]={to, cost}, O(ElogV)
    public:
        vector<int> dist;
        dijkstra(int start, const vector<vector<pair<int,int> > > &graph, vector<vector<int> >& edge)
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
                    if(edge[now][next.first]==0) continue;
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

void erase_edge(int now, vector<set<int> >& prev, vector<vector<int> >& edge, vector<int>& visited)
{   
    for(auto next : prev[now])
    {
        edge[next][now]=0;
        if(!visited[next])
        {
            erase_edge(next, prev, edge, visited);
            visited[next]=1;
        }
    }
}

int main(void)
{
#ifdef LOCAL
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    while(n or m)
    {
        int s, d; scanf("%d%d", &s, &d);
        vector<vector<pair<int,int> > > graph(n+1);
        for(int i=0; i<m; i++)
        {
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            graph[a].push_back({b, c});
        }
        vector<vector<int> > edge(n+1, vector<int>(n+1, 1));

        vector<int> dist(n+1, INT32_MAX/2);
        dist[s]=0;
        vector<set<int> > prev(n+1);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        pq.push({0, s});
        while(pq.size())
        {
            auto [now_cost, now]=pq.top();
            pq.pop();

            if(now_cost > dist[now]) continue;
            for(auto [next, cost] : graph[now])
            {
                int next_cost=now_cost+cost;
                if(next_cost == dist[next])
                    prev[next].insert(now);
                else if(next_cost < dist[next])
                {
                    prev[next].clear();
                    dist[next]=next_cost;
                    pq.push({next_cost, next});
                    prev[next].insert(now);
                }
            }
        }

        vector<int> visited(n+1);
        erase_edge(d, prev, edge, visited);
        
        dijkstra second(s, graph, edge);
        printf("%d\n", second.dist[d]==INT32_MAX/2 ? -1:second.dist[d]); 

        scanf("%d%d", &n, &m);
    }

}

/*
    
*/