// https://www.acmicpc.net/problem/25307
// 2022-07-26 01:39:51 600ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    vector<vector<int> > table(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &table[i][j]);
    
    const int way[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};

    // 마네킹 있는 칸과 거리가 k이하인 칸 처리
    queue<pair<int,pair<int,int> > > q;
    vector<vector<int> > visited(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(table[i][j]==3)
            {
                q.push({0, {i, j}});
                visited[i][j]=0;
            }

    while(q.size())
    {
        int cnt=q.front().first, x=q.front().second.first, y=q.front().second.second;
        q.pop();

        if(cnt > k) continue;

        if(!table[x][y] or table[x][y]==2) 
            table[x][y]=1; // 못 지나가는 칸으로 간주

        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(0<=nx and nx<n and 0<=ny and ny<m)
                if(!visited[nx][ny]) 
                    q.push({cnt+1, {nx, ny}}), visited[nx][ny]=1;
        }
    }

    // 지금 자리에서 의자까지 최단거리 구하기
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(table[i][j]==4)
            {
                q.push({0, {i, j}});
                visited[i][j]=0;
            }

    visited.assign(n, vector<int>(m));
    while(q.size())
    {
        int cnt=q.front().first, x=q.front().second.first, y=q.front().second.second;
        q.pop();

        if(table[x][y]==2)
            return !printf("%d", cnt);
        
        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(0<=nx and nx<n and 0<=ny and ny<m)
                if(!table[nx][ny] or table[nx][ny]==2) 
                    if(!visited[nx][ny])
                        q.push({cnt+1, {nx, ny}}), visited[nx][ny]=1;
        }
    }
    printf("-1");
}


/*
    
*/