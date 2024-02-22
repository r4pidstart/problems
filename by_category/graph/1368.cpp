// https://www.acmicpc.net/problem/1368
// 2024-02-22 00:46:05
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<pair<int, int> > > graph(n+1);

    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        graph[0].push_back({i+1, a});
        graph[i+1].push_back({0, a});
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            int a; scanf("%d", &a);
            if(i!=j)
                graph[i-1].push_back({j-1, a});
        }
    
    vector<int> used(n+1);
    priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, 0});

    int ans=0;
    while(pq.size())
    {
        auto [c, now]=pq.top();
        pq.pop();

        if(used[now]) continue;

        used[now]=1;
        ans+=c;

        for(auto [next, cost] : graph[now])
        {
            if(!used[next])
                pq.push({cost, next});
        }
    }

    printf("%d", ans);
}

/*
    
*/