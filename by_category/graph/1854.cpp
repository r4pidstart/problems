// https://www.acmicpc.net/problem/
// 2022-12-03 02:05:38
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b,c});
    }
    
    vector<priority_queue<int> > dist(n);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<> > pq;
    pq.push({0, 1});
    dist[0].push(0);
    while(pq.size())
    {
        auto [now_cost, now]=pq.top();
        pq.pop();

        for(auto [next, cost] : graph[now])
        {
            if(dist[next-1].size() < k)
            {
                pq.push({now_cost + cost, next});
                dist[next-1].push(now_cost + cost);
            }
            else if(now_cost + cost < dist[next-1].top())
            {
                dist[next-1].pop();
                pq.push({now_cost + cost, next});
                dist[next-1].push(now_cost + cost);
            }
        }
    }

    for(auto it : dist)
        printf("%d\n", it.size()!=k ? -1:it.top());
}

/*
    
*/