// https://www.acmicpc.net/problem/14554
// 2023-03-31 23:07:58
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,s,e; scanf("%d%d%d%d", &n, &m, &s, &e);
    vector<vector<pair<int, int> > > graph(n+1);
    for(int i=0; i<m; i++) 
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }  

    vector<long> dist(n+1, LLONG_MAX), cnt(n+1, 0);
    cnt[s]=1, dist[s]=0;
    priority_queue<pair<long, int>, vector<pair<long, int> >, greater<> > pq;
    pq.push({0, s});
    
    while(pq.size())
    {
        auto [now_dist, now]=pq.top();  
        pq.pop();

        if(now_dist > dist[now]) continue;

        for(auto [next, ndist] : graph[now])
        {
            if(dist[next] > now_dist+ndist)
            {
                cnt[next]=cnt[now];
                dist[next]=now_dist+ndist;
                pq.push({now_dist+ndist, next});
            }
            else if(dist[next] == now_dist+ndist)
                cnt[next]=(cnt[next]+cnt[now])%(int)(1e9+9);
        }
    }
    printf("%ld", cnt[e]);
}

/*
    
*/