// https://www.acmicpc.net/problem/2648
// 2022-03-12 02:22:39 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<vector<int> > table(301, vector<int>(301,0));

    int x,y; scanf("%d%d", &y, &x);
    x=x*2-1+100, y=y*2-1+100;
    table[x][y]=1;

    // draw line
    int n; scanf("%d", &n);
    while(n--)
    {
        char cmd; int cnt; scanf(" %c %d", &cmd, &cnt);
        cnt=cnt*2;
        while(cnt--)
        {
            switch(cmd)
            {
                case 'R':
                    table[x][++y]=1;
                    break;
                case 'L':
                    table[x][--y]=1;
                    break;
                case 'U':
                    table[++x][y]=1;
                    break;
                case 'D':
                    table[--x][y]=1;
                    break;
            }
        }
    }

    // for(int i=210; i>=200; i--)
    // {
    //     for(int j=200; j<210; j++)
    //         printf("%d", table[i][j]);
    //     printf("\n");
    // }

    // bfs
    int ans=INT32_MAX;
    pair<int,int> a1, a2;
    const int mov[4][2]={{0,1}, {1,0}, {-1,0}, {0,-1}};
    vector<vector<int> > visited(301, vector<int>(301,0));
    for(int i=0; i<=300; i++)
        for(int j=0; j<=300; j++)
        {
            if(table[i][j] or visited[i][j]) continue;
            int tmp=0;
            queue<pair<int, int> > q;
            q.push({i, j});
            
            pair<int,int> lb={i,j}, rt={i,j};
            while(!q.empty())
            {
                auto [x,y]=q.front(); q.pop();
                if(visited[x][y]) continue;
                visited[x][y]=1, tmp++;
                lb=min(lb, {x-1,y-1}), rt=max(rt, {x+1,y+1});

                for(int i=0; i<4; i++)
                {
                    int nx=x+mov[i][0], ny=y+mov[i][1];
                    if(0<=nx and nx<=300 and 0<=ny and ny<=300 and !visited[nx][ny] and !table[nx][ny])
                        q.push({nx, ny});
                }
            }

            // rectangle check
            if(tmp == (rt.first-lb.first-1) * (rt.second-lb.second-1))
                if(ans > tmp)
                    ans=tmp, a1=lb, a2=rt;
        }
    
    if(ans > 10000) return !printf("0");
    printf("%d %d\n%d %d", (a1.second+1)/2-50, (a1.first+1)/2-50, (a2.second+1)/2-50, (a2.first+1)/2-50);
}

/*
    
*/