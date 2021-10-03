// https://www.acmicpc.net/problem/1261
// 2021-09-28 02:53:18 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &m, &n);
    vector<vector<int> > field(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d", &field[i][j]);
    
    // dijkstra
    vector<vector<int> > dist(n, vector<int>(m, INT32_MAX/2));
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
    pq.push({0,{0,0}});
    // dist, {x, y}
    dist[0][0]=0;

    const int move[4][2]={{0,1}, {1,0}, {-1,0}, {0,-1}};
    while(!pq.empty())
    {
        int now_dist=pq.top().first;
        pair<int, int> now=pq.top().second;
        pq.pop();

        if(now_dist > dist[now.first][now.second]) continue;

        for(int w=0; w<4; w++)
        {
            int nx=now.first+move[w][0], ny=now.second+move[w][1];
            if(!(0<=nx && nx<n && 0<=ny && ny<m)) continue;
            if(dist[nx][ny] > now_dist+field[nx][ny])
            {
                dist[nx][ny]=now_dist+field[nx][ny];
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
    }
    printf("%d", dist[n-1][m-1]);
}

/*
    
*/