// https://www.acmicpc.net/problem/6087
// 2024-03-08 22:27:21
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    swap(n,m);
    vector<vector<char> > table(n, vector<char>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &table[i][j]);
    
    int sx,sy;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(table[i][j]=='C') sx=i, sy=j;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<> > pq;
    vector<vector<vector<int> > > dist(n, vector<vector<int> >(m, vector<int>(4, INT32_MAX/2)));
    for(int i=0; i<4; i++)
        dist[sx][sy][i]=0, pq.push({sx, sy, i});

    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    while(pq.size())
    {
        auto [x, y, d]=pq.top();
        pq.pop();

        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(0<=nx and nx<n and 0<=ny and ny<m and table[nx][ny] != '*' and dist[nx][ny][w] > dist[x][y][d]+(d!=w))
            {
                dist[nx][ny][w]=dist[x][y][d]+(d!=w);
                pq.push({nx, ny, w});
            }
        }
    }

    int ans=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(table[i][j]=='C')
            {
                ans=*min_element(dist[i][j].begin(), dist[i][j].end());
                return !printf("%d", ans);
            }
}

/*
    
*/