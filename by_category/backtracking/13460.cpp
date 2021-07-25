// https://www.acmicpc.net/problem/13460
// 2021-07-25 21:11:14 0ms
#include<bits/stdc++.h>
using namespace std;

const int w[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<vector<char> > field;
    field.assign(n,vector<char>(m,0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" \n%c", &field[i][j]);

    int visited[n][m][n][m]={};
    queue<pair<int, vector<vector<char> > > > q;
    q.push({0, field});

    while(!q.empty())
    {
        auto target=q.front();
        q.pop();
        if(target.first>9)
        {
            printf("-1");
            return 0;
        }

        int rx,ry;
        for(int x=0; x<n; x++)
            for(int y=0; y<m; y++)
                if(target.second[x][y]=='R')
                    rx=x, ry=y;
        int bx,by;
        for(int x=0; x<n; x++)
            for(int y=0; y<m; y++)
                if(target.second[x][y]=='B')
                    bx=x, by=y;

        if(visited[rx][ry][bx][by])
            continue;
        
        visited[rx][ry][bx][by]++;

        for(int i=0; i<4; i++)
        {
            auto tmp=target.second;
            int flag=0, clear=0;

            // R
            int rx,ry;
            for(int x=0; x<n; x++)
                for(int y=0; y<m; y++)
                    if(tmp[x][y]=='R')
                        rx=x, ry=y;

            while(true)
            {
                int nx=rx+w[i][0], ny=ry+w[i][1];
                if(!(0<=nx && nx<n && 0<=ny && ny<m)) break;
                if(tmp[nx][ny]=='#' || tmp[nx][ny]=='B') break;
                if(tmp[nx][ny]=='O')
                {
                    clear++;
                    tmp[nx][ny]='R', tmp[rx][ry]='O';
                    rx=nx, ry=ny;
                }
                else
                {
                    tmp[nx][ny]='R', tmp[rx][ry]='.';
                    rx=nx, ry=ny;
                }
            }
            // B
            int bx,by;
            for(int x=0; x<n; x++)
                for(int y=0; y<m; y++)
                    if(tmp[x][y]=='B')
                        bx=x, by=y;

            while(true)
            {
                int nx=bx+w[i][0], ny=by+w[i][1];
                if(!(0<=nx && nx<n && 0<=ny && ny<m)) break;
                if(tmp[nx][ny]=='#' || tmp[nx][ny]=='R') break;
                if(tmp[nx][ny]=='O')
                    flag++;
                tmp[nx][ny]='B', tmp[bx][by]='.';
                bx=nx, by=ny;
            }

            if(flag)
                continue;

            // R
            while(true)
            {
                int nx=rx+w[i][0], ny=ry+w[i][1];
                if(!(0<=nx && nx<n && 0<=ny && ny<m)) break;
                if(tmp[nx][ny]=='#' || tmp[nx][ny]=='B') break;
                if(tmp[nx][ny]=='O')
                {
                    clear++;
                    tmp[nx][ny]='R', tmp[rx][ry]='O';
                    rx=nx, ry=ny;
                }
                tmp[nx][ny]='R', tmp[rx][ry]='.';
                rx=nx, ry=ny;
            }

            if(clear)
            {
                printf("%d", target.first+1);
                return 0;
            }
            q.push({target.first+1, tmp});
        }
    }
    printf("-1");
}

/*

*/
