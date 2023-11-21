// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n, m; scanf("%d%d", &n, &m);
    int sx, sy, ex, ey;
    vector<vector<int> > table(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            scanf(" %c", &table[i][j]);
            if(table[i][j] == 'S') sx=i, sy=j;
            if(table[i][j] == 'F') ex=i, ey=j;
        }
            
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    // dijkstra
    // cost x y passed_trash
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int> >, greater<> > pq;
    vector<vector<vector<int> > > dist(n, vector<vector<int> >(m, vector<int>(200, INT32_MAX/2)));
    pq.emplace(0, sx, sy, 0);
    dist[sx][sy][0]=0;

    while(pq.size())
    {
        auto [c, x, y, cnt]=pq.top();
        pq.pop();
        if(dist[x][y][cnt] < c) continue;
        if(cnt > 150) continue;

        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(0<=nx and nx<n and 0<=ny and ny<m)
            {
                if(table[nx][ny]=='g')
                {
                    if(dist[nx][ny][cnt+1] > c)
                        pq.emplace(c, nx, ny, cnt+1), dist[nx][ny][cnt+1]=c;
                }
                else
                {
                    // check adjacent
                    int flag=0;
                    if(table[nx][ny]=='.')
                    {
                        for(int i=0; i<4; i++)
                        {
                            int nnx=nx+way[i][0], nny=ny+way[i][1];
                            // if(nnx==x and nny==y) continue;
                            if(0<=nnx and nnx<n and 0<=nny and nny<m)
                                if(table[nnx][nny]=='g') flag=1;
                        }
                    }
                    if(dist[nx][ny][cnt] > c+flag)
                        pq.emplace(c+flag, nx, ny, cnt), dist[nx][ny][cnt]=c+flag;
                }
            }
        }
    }
    for(int i=0; i<200; i++)
        if(dist[ex][ey][i]!=INT32_MAX/2)
            return !printf("%d %d\n", i, dist[ex][ey][i]);
}

/*
    
*/