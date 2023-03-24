// https://www.acmicpc.net/problem/11085
// 2023-03-25 01:54:51
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    int s,e; scanf("%d%d", &s, &e);

    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    vector<int> tmp(n+1, -1);
    priority_queue<pair<int,int> > pq; // width, point
    pq.push({INT32_MAX, s});
    tmp[s]=INT32_MAX;

    while(pq.size())
    {
        auto [width, now]=pq.top();
        pq.pop();

        if(width < tmp[now]) continue;

        for(auto& [next, next_width] : graph[now])
        {
            int width_min=min(width, next_width);
            if(tmp[next] < width_min)
            {
                tmp[next]=width_min;
                pq.push({width_min, next});
            }
        }
    }

    printf("%d", tmp[e]);
}

/*
    
*/