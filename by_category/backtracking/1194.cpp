// https://www.acmicpc.net/problem/1194
// 2021-06-19 22:19:49 0ms
#include<bits/stdc++.h>
using namespace std;

struct argu
{
    int x,y, mask, cnt;
};

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    const int way[4][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};
    char maze[n][m];
    int visited[n][m][1<<6]={};
    pair<int,int> start;
    getchar();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%c", &maze[i][j]);
            if(maze[i][j]=='0')
                start={i,j};
        }
        getchar();
    }

    // bitmask bfs
    queue<argu> bfs;
    bfs.push({start.first, start.second, 0, 0});
    visited[start.first][start.second][0]=1;
    while(!bfs.empty())
    {
        argu now=bfs.front();
        bfs.pop();
        for(int i=0; i<4; i++)
        {
            int nx=now.x+way[i][0], ny=now.y+way[i][1];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;

            int next=maze[nx][ny], mask=now.mask;
            if(next=='#') 
                continue;

            else if('A'<=next && next<='F' && !(mask & (1<<(next-'A')))) 
                continue;

            else if('a'<=next && next<='f')
                mask=mask|(1<<(next-'a'));
            
            else if(next=='1')
            {
                printf("%d", now.cnt+1);
                return 0;
            }

            if(visited[nx][ny][mask]==0)
            {
                visited[nx][ny][mask]=1;
                bfs.push({nx, ny, mask, now.cnt+1});
            }
        }
    }
    printf("-1");
}