// https://www.acmicpc.net/problem/11952
// 2023-08-10 00:44:16
#include"bits/stdc++.h"
using namespace std;

#define int long

signed main(void)
{
#ifdef LOCAL
#endif
    int n,m,k,s; scanf("%ld%ld%ld%ld", &n, &m, &k, &s);
    int p,q; scanf("%ld%ld", &p, &q);
    queue<pair<int,int> > qu;
    for(int i=0; i<k; i++)
    {
        int a; scanf("%ld", &a);
        qu.push({a, 0});
    }
    vector<vector<int> > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%ld%ld", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> dangerous(n+1), infected(n+1);
    while(qu.size())
    {
        auto [now, cnt]=qu.front();
        qu.pop();

        if(cnt==0) infected[now]=1;
        else dangerous[now]=1;

        if(cnt==s) continue;
        for(int next : graph[now])
            if(!dangerous[next])
                qu.push({next, cnt+1});
    }

    priority_queue<pair<int, int>, vector<pair<int,int> >, greater<> > pq;
    vector<int> dist(n+1, LLONG_MAX/2);
    dist[1]=0;
    pq.push({0, 1});
    while(pq.size())
    {
        auto [cost, now]=pq.top();
        pq.pop();

        if(dist[now]<cost) continue;
        for(auto next : graph[now])
        {
            if(infected[next]) continue;
            int ncost=cost+(dangerous[next] ? q:p);
            if(ncost < dist[next])
            {
                dist[next]=ncost;
                pq.push({ncost, next});
            }
        }
    }
    printf("%ld", dist[n]-(dangerous[n] ? q:p));
}

/*

*/