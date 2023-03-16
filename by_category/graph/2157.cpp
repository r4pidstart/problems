// https://www.acmicpc.net/problem/2157
// 2023-03-16 19:35:11
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0; i<k; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        if(a<b)
        {
            int flag=0;
            for(int j=0; j<graph[a].size(); j++)
                if(graph[a][j].first==b) graph[a][j].second=max(graph[a][j].second, c), flag=1;
            if(!flag)
                graph[a].push_back({b, c});
        }
    }

    vector<vector<int> > dist(n+1, vector<int>(m+1, 0));
    priority_queue<tuple<int, int, int> > pq;
    // dist, cnt, loca
    pq.push({0, 1, 1});
    while(pq.size())
    {
        auto [nowdist, cnt, loca]=pq.top();
        pq.pop();

        if(dist[loca][cnt] < nowdist) continue;
        if(cnt==m) continue;
        
        for(auto [next, d] : graph[loca])
        {
            int nextdist=nowdist+d;
            if(dist[next][cnt+1] < nextdist)
                dist[next][cnt+1]=nextdist, pq.push({nextdist, cnt+1, next});
        }
    }

    printf("%d", *max_element(dist[n].begin(), dist[n].end()));
}

/*
    
*/