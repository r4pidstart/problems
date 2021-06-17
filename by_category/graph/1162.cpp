// https://www.acmicpc.net/problem/1162
// 2021-06-17 17:35:59 104ms
#include<bits/stdc++.h>
using namespace std;

const long long INF=INT64_MAX/2;
int main(void)
{
    int n, m, k; scanf("%d%d%d", &n,&m,&k);
    vector<vector<pair<int, int> > > edge(n+1);
    vector<vector<long long> > dist(n+1, vector<long long>(k+1, INF)); // dist[정점][포장 횟수]

    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }

    priority_queue<pair<pair<long long, int>, int>, vector<pair<pair<long long, int>, int> > , greater<pair<pair<long long, int>, int> > > pq; 
    // d, now, cnt
    dist[1][0]=0;
    pq.push({{0, 1}, 0});

    while(!pq.empty())
    {
        long long d=pq.top().first.first;
        int now=pq.top().first.second, cnt=pq.top().second;
        pq.pop();

        if(d > dist[now][cnt])
            continue;

        for(auto& next : edge[now])
        {
            int next_city=next.first;
            long long next_dist=next.second;
            if(next_dist+d < dist[next_city][cnt]) // 포장 안 하는 경우
            {
                dist[next_city][cnt]=next_dist+d;
                pq.push({{next_dist+d, next_city}, cnt});
            }
            if(cnt!=k && d < dist[next_city][cnt+1]) // 포장 하는 경우
            {
                dist[next_city][cnt+1]=d;
                pq.push({{d, next_city}, cnt+1});
            }
        }
    }

    long long ans=INF;
    for(int i=0; i<=k; i++)
        ans=min(ans, dist[n][i]);

    printf("%lld", ans);
}