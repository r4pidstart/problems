// https://www.acmicpc.net/problem/1238
// 2021-07-01 23:21:12 4ms
#include<bits/stdc++.h>
using namespace std;

int n,m,x; 
vector<vector<vector<pair<int,int> > > > dest;
vector<vector<int> > dist;

void dijkstra(int start, int rev)
{
    priority_queue<pair<int, int> > pq;
    pq.push({0, start});
    dist[rev][start]=0;

    while(!pq.empty())
    {
        int now_v=pq.top().second, now_dist=-pq.top().first;
        pq.pop();

        for(auto& next : dest[rev][now_v])
        {
            int next_v=next.first, next_dist=next.second;
            if(dist[rev][next_v] > now_dist+next_dist)
            {
                dist[rev][next_v]=now_dist+next_dist;
                pq.push({-dist[rev][next_v], next_v});
            }
        }
    }
}

int main(void)
{
    scanf("%d%d%d", &n, &m, &x);
    dest.assign(2, vector<vector<pair<int,int> > >(n+1));
    dist.assign(2, vector<int>(n+1, INT32_MAX/2));
    for(int i=0; i<m; i++)
    {
        int a, b, c; scanf("%d%d%d", &a,&b,&c);
        dest[0][a].push_back({b,c});
        dest[1][b].push_back({a,c});
    }

    // dijkstra O(n*logn)
    dijkstra(x,0); // x to home
    dijkstra(x,1); // home to x 

    int ans=0;
    for(int i=1; i<=n; i++)
        ans=max(ans, dist[0][i]+dist[1][i]);
    printf("%d", ans);
}

/*
    다익스트라에 간선을 거꾸로 넣으면, 시작 정점으로부터 모든 정점으로까지의 최단 거리를 구할 수 있음.
*/