// https://www.acmicpc.net/problem/1238
// 2021-07-01 23:09:06 124ms
#include<bits/stdc++.h>
using namespace std;

int n,m,x; 
vector<vector<pair<int,int> > > dest;
vector<vector<int> > dist;

void dijkstra(int start)
{
    priority_queue<pair<int, int> > pq;
    pq.push({0, start});
    dist[start][start]=0;

    while(!pq.empty())
    {
        int now_v=pq.top().second, now_dist=-pq.top().first;
        pq.pop();

        for(auto& next : dest[now_v])
        {
            int next_v=next.first, next_dist=next.second;
            if(dist[start][next_v] > now_dist+next_dist)
            {
                dist[start][next_v]=now_dist+next_dist;
                pq.push({-dist[start][next_v], next_v});
            }
        }
    }
}

int main(void)
{
    scanf("%d%d%d", &n, &m, &x);
    dest.assign(n+1, vector<pair<int,int> >());
    dist.assign(n+1, vector<int>(n+1, INT32_MAX/2));
    for(int i=0; i<m; i++)
    {
        int a, b, c; scanf("%d%d%d", &a,&b,&c);
        dest[a].push_back({b,c}); // 단방향
    }

    // dijkstra O(n^2*logn)
    for(int i=1; i<=n; i++)
        dijkstra(i);

    int ans=0;
    for(int i=1; i<=n; i++)
        ans=max(ans, dist[i][x]+dist[x][i]);
    printf("%d", ans);
}

/*

*/