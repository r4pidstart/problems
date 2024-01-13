// https://www.acmicpc.net/problem/31230
// 2024-01-14 02:54:49
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,a,b; scanf("%d%d%d%d", &n, &m, &a, &b);
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    vector<set<int> > indegree(n+1);
    vector<long> dist(n+1, LONG_MAX/2);
    priority_queue<pair<long, int>, vector<pair<long, int> >, greater<> > pq;
    pq.push({0, a});
    dist[a]=0;

    while(pq.size())
    {
        auto [now_dist, now]=pq.top();
        pq.pop();

        if(dist[now] < now_dist) continue;

        for(auto [next, next_dist] : graph[now])
        {
            long ndist=now_dist+next_dist;
            if(ndist == dist[next])
                indegree[next].insert(now);
            else if(ndist < dist[next])
            {
                indegree[next]=set<int>{now};
                dist[next]=ndist;
                pq.push({ndist, next});
            }
        }
    }

    set<int> ans;
    queue<int> q;
    q.push(b);
    ans.insert(b);

    while(q.size())
    {
        int now=q.front();
        q.pop();

        for(int next : indegree[now])
            if(ans.find(next) == ans.end())
                ans.insert(next), q.push(next);
    }

    printf("%d\n", ans.size());
    for(int i : ans)
        printf("%d ", i);
}

/*
    
*/