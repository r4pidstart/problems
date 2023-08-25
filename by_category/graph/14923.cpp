// https://www.acmicpc.net/problem/14923
// 2023-08-26 05:25:08
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n, m, hx, hy, ex, ey;
    scanf("%d%d%d%d%d%d", &n, &m, &hx, &hy, &ex, &ey);
    hx--, hy--, ex--, ey--;
    vector<vector<int> > table(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &table[i][j]);
    
    vector<vector<vector<int> > > visited(n, vector<vector<int> >(m, vector<int>(2)));
    queue<tuple<int,int,int,int> > q;
    visited[hx][hy][0]=1;
    q.push({hx, hy, 0, 0});
    while(q.size())
    {
        auto [x, y, magic, cnt]=q.front();
        q.pop();

        if(x==ex and y==ey)
            return !printf("%d", cnt);
        
        const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        for(int i=0; i<4; i++)
        {
            int nx=x+way[i][0], ny=y+way[i][1];
            if(0<=nx and nx<n and 0<=ny and ny<m)
            {
                if(table[nx][ny] and !magic)
                {
                    q.push({nx, ny, 1, cnt+1});
                    visited[nx][ny][1]=1;
                }
                else if(!table[nx][ny] and !visited[nx][ny][magic])
                {
                    q.push({nx, ny, magic, cnt+1});
                    visited[nx][ny][magic]=1;
                }
            }
        }
    }
    printf("-1");
}

/*
    
*/