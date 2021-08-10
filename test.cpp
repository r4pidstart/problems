// https://www.acmicpc.net/problem/
// 
#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int> > > graph;
vector<int> dist, route;

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n,&m,&k);
    int s,d; scanf("%d%d", &s,&d);

    graph.assign(n, vector<pair<int,int> >());
    dist.assign(n,0), route.assign(n,0);

    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        graph[a-1].push_back({b-1,c});
        graph[b-1].push_back({a-1,c});
    }
    
    // find shortest route
    fill(dist.begin(), dist.end(), INT32_MAX/2);
    fill(route.begin(), route.end(), -1);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push({0,s-1});
    dist[s-1]=0;
    while(!pq.empty())
    {
        int now=pq.top().second, now_dist=pq.top().first;
        pq.pop();

        if(dist[now] < now_dist) continue;
        for(auto next : graph[now])
        {
            int next_dist=now_dist+1;
            if(dist[next.first] > next_dist)
            {
                dist[next.first]=next_dist;
                pq.push({next_dist, next.first});
                route[next.first]=now;
            }
        }
    }
    int s_route_dist=dist[d-1];
    deque<int> s_route;
    int now=d-1;
    while(route[now]!=-1)
    {
        s_route.push_back(now);
        now=route[now];
    }

    int flag=0, tax=0, ans;
    for(int i=0; i<=k; i++)
    {
        if(flag)
        {
            ans+=s_route_dist;
            printf("%d\n", ans);
            continue;   
        }

        if(i!=0)
        {
            int tax_update; scanf("%d", &tax_update);
            tax+=tax_update;
        }

        // dijkstra
        fill(dist.begin(), dist.end(), INT32_MAX/2);
        fill(route.begin(), route.end(), -1);
        pq.push({0,s-1});
        dist[s-1]=0;
        while(!pq.empty())
        {
            int now=pq.top().second, now_dist=pq.top().first;
            pq.pop();

            if(dist[now] < now_dist) continue;
            for(auto next : graph[now])
            {
                int next_dist=now_dist+next.second+tax;
                if(dist[next.first] > next_dist)
                {
                    dist[next.first]=next_dist;
                    pq.push({next_dist, next.first});
                    route[next.first]=now;
                }
            }
        }

        // check whether shortest route and this route are the same
        deque<int> n_route;
        int now=d-1;
        while(route[now]!=-1)
        {
            n_route.push_back(now);
            now=route[now];
        }

        if(n_route==s_route)
            flag++, ans=dist[d-1];

        printf("%d\n", dist[d-1]);
    }
}

/*

*/