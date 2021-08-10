// https://www.acmicpc.net/problem/13907
// 2021-08-11 01:13:45 1420ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int> > > graph;
vector<vector<int> > dist;

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n,&m,&k);
    int s,d; scanf("%d%d", &s,&d);

    graph.assign(n, vector<pair<int,int> >());
    dist.assign(n,vector<int>(n, INT32_MAX/2));

    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        graph[a-1].push_back({b-1,c});
        graph[b-1].push_back({a-1,c});
    }
    
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int,pair<int,int> > > >pq;
    pq.push({0,{0,s-1}});
    for(int i=0; i<n; i++)
        dist[i][s-1]=0;

    while(!pq.empty())
    {
        int now=pq.top().second.second, now_dist=pq.top().first, now_cnt=pq.top().second.first;
        pq.pop();

        if(dist[now_cnt][now] < now_dist) continue;
        if(now_cnt+1 >= n) continue;
        for(auto next : graph[now])
        {
            int next_dist=now_dist+next.second;
            if(dist[now_cnt+1][next.first] > next_dist)
            {
                dist[now_cnt+1][next.first]=next_dist;
                pq.push({next_dist, {now_cnt+1, next.first}});
            }
        }
    }
    
    int min_cost=INT32_MAX/2;
    for(int i=0; i<n; i++)
        min_cost=min(min_cost, dist[i][d-1]);
    printf("%d\n", min_cost);

    for(int i=0; i<k; i++)
    {
        int tax_update, min_cost=INT32_MAX/2; scanf("%d", &tax_update);
        for(int j=0; j<n; j++)
        {
            dist[j][d-1]+=(j*tax_update);
            min_cost=min(min_cost, dist[j][d-1]);
        }
        printf("%d\n", min_cost);
    }
}

/*

*/