// https://www.acmicpc.net/problem/25307
// 2022-06-25 23:31:51 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    vector<vector<int> > table(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &table[i][j]);
    
    const int way[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};

    // 시작지점 마네킹과 K이하 처리
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(table[i][j]==4)
            {
                queue<pair<int,pair<int,int> > > q;
                vector<vector<int> > visited(n, vector<int>(n));
                q.push({0, {i, j}});
                while(q.size())
                {
                    int cnt=q.front().first, x=q.front().second.first, y=q.front().second.second;
                    q.pop();

                    if(cnt > k or visited[x][y]) continue;
                    visited[x][y]=1;

                    if(!table[x][y]) 
                        table[x][y]=5; // 여긴 마네킹 있어도 지나갈 수 있는것
                    for(int w=0; w<4; w++)
                    {
                        int nx=x+way[w][0], ny=y+way[w][1];
                        if(0<=nx and nx<n and 0<=ny and ny<n)
                            if(!visited[nx][ny]) q.push({cnt+1, {nx, ny}});
                    }
                }
                goto next;
            }

    next:
    // 마네킹 있는 칸과 거리가 k이하인 칸 처리
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(table[i][j]==3)
            {
                queue<pair<int,pair<int,int> > > q;
                vector<vector<int> > visited(n, vector<int>(n));
                q.push({0, {i, j}});
                while(q.size())
                {
                    int cnt=q.front().first, x=q.front().second.first, y=q.front().second.second;
                    q.pop();

                    if(cnt > k or visited[x][y]) continue;
                    visited[x][y]=1;

                    if(!table[x][y] or table[x][y]==2) 
                        table[x][y]=1; // 못 지나가는 칸으로 간주
                    for(int w=0; w<4; w++)
                    {
                        int nx=x+way[w][0], ny=y+way[w][1];
                        if(0<=nx and nx<n and 0<=ny and ny<n)
                            if(!visited[nx][ny]) q.push({cnt+1, {nx, ny}});
                    }
                }
            }

    // 지금 자리에서 의자까지 최단거리 구하기
    queue<pair<int,pair<int,int> > > q;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(table[i][j]==4)
            {
                q.push({0, {i, j}});
            }
    while(q.size())
    {
        int cnt=q.front().first, x=q.front().second.first, y=q.front().second.second;
        q.pop();

        if(table[x][y]==2)
            return !printf("%d", cnt);
        table[x][y]=1; // 방문체크 귀찮
        
        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(0<=nx and nx<n and 0<=ny and ny<n)
                if(!table[nx][ny] or table[nx][ny]==2 or table[nx][ny]==5) q.push({cnt+1, {nx, ny}});
        }
    }
    printf("-1");
}


/*
    
*/