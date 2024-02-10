// https://www.acmicpc.net/problem/14167
// 2024-02-08 01:22:26
#include"bits/stdc++.h"
using namespace std;

inline long get_dist(const pair<int,int>& a, const pair<int,int>& b)
{
    return (1L*a.first-b.first)*(1L*a.first-b.first)+(1L*a.second-b.second)*(1L*a.second-b.second);
}
int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > cow(n);
    for(int i=0; i<n; i++)
        scanf("%d %d", &cow[i].first, &cow[i].second);
    
    vector<vector<pair<int, long> > > graph(n);
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            graph[i].push_back({j, get_dist(cow[i], cow[j])});
            graph[j].push_back({i, get_dist(cow[i], cow[j])});
        }
    
    long ans=0;
    vector<int> used(n);
    priority_queue<pair<long, int>, vector<pair<long, int> >, greater<> > pq;
    pq.push({0, 0});

    while(pq.size())
    {
        auto [dist, now]=pq.top();
        pq.pop();

        if(used[now]) continue;
        used[now]=1;

        ans=max(ans, dist);

        for(auto [next, ndist] : graph[now])
            if(!used[next])
                pq.push({ndist, next});
    }
    printf("%ld", ans);
}

/*
    
*/