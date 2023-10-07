// https://www.acmicpc.net/problem/20183
// 2023-10-07 19:51:27
#include"bits/stdc++.h"
using namespace std;

int decision(int s, int e, vector<vector<pair<int, int> > >& graph, int mid, long c)
{
    vector<long> cost(graph.size(), -1);
    priority_queue<pair<long, int>, vector<pair<long, int> >, greater<> > pq;

    cost[s]=0;
    pq.push({0, s});

    while(pq.size())
    {
        auto [nowcost, now]=pq.top();
        pq.pop();

        if(nowcost > c) return 0;
        if(now==e) return 1;

        if(nowcost > cost[now]) continue;

        for(auto [next, edgecost] : graph[now])
        {
            if(edgecost > mid) continue;
            long ncost=nowcost+edgecost;
            if(cost[next]==-1 or ncost<cost[next])
                pq.push({ncost, next}), cost[next]=ncost;
        }
    }
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    long n,m,s,e,c; scanf("%ld%ld%ld%ld%ld", &n, &m, &s, &e, &c);

    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int lo=0, hi=1e9, ans=2e9;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(s, e, graph, mid, c))
            hi=mid-1, ans=mid;
        else
            lo=mid+1;
    }
    if(ans==2e9) printf("-1");
    else printf("%d", ans);
}

/*
    
*/