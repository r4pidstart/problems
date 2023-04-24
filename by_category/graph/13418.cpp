// https://www.acmicpc.net/problem/13418
// 2023-04-24 23:05:14
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0; i<m+1; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b, !c});
        graph[b].push_back({a, !c});
    }

    int ans_min=0, ans_max=0;

{
    // min
    int cnt=0;
    priority_queue<pair<int, int>, vector<pair<int,int> >, greater<> > pq;
    vector<int> used(n+1);
    pq.push({0, 0});
    while(pq.size())
    {
        auto [is_up, now]=pq.top(); pq.pop();

        if(used[now]) continue;
        if(is_up) ans_min++;
        used[now]=1;

        for(auto next : graph[now])
            pq.push({next.second, next.first});
    }
}

{
    // max
    int cnt=0;
    priority_queue<pair<int, int> > pq;
    vector<int> used(n+1);
    pq.push({0, 0});
    while(pq.size())
    {
        auto [is_up, now]=pq.top(); pq.pop();

        if(used[now]) continue;
        if(is_up) ans_max++;
        used[now]=1;

        for(auto next : graph[now])
            pq.push({next.second, next.first});
    }
}
    printf("%d", ans_max*ans_max - ans_min*ans_min);
}

/*
    
*/