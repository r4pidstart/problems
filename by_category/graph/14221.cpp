// https://www.acmicpc.net/problem/14221
// 2021-08-12 22:05:19 56ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int> > > graph;
vector<int> house, dist;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    graph.assign(n+1, vector<pair<int,int> >());
    dist.assign(n+1, INT32_MAX/2);

    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        graph[a-1].push_back({b-1,c});
        graph[b-1].push_back({a-1,c});
    }

    int p,q; scanf("%d%d", &p,&q);
    for(int i=0; i<p; i++)
    {
        int a; scanf("%d", &a);
        house.push_back(a-1);
    }

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    for(int i=0; i<q; i++)
    {
        int a; scanf("%d", &a);
        pq.push({dist[a-1]=0, a-1});
    }

    // dijkstra
    while(!pq.empty())
    {
        auto now=pq.top();
        pq.pop();

        if(now.first > dist[now.second]) continue;
        for(auto& next : graph[now.second])
        {
            int next_dist=now.first+next.second;
            if(next_dist < dist[next.first])
                pq.push({dist[next.first]=next_dist, next.first});
        }
    }

    pair<int,int> ans={INT32_MAX, INT32_MAX};
    for(int h : house)
        ans=min(ans, {dist[h], h});
    printf("%d", ans.second+1);
}

/*

*/