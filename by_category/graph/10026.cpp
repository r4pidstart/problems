// https://www.acmicpc.net/problem/10026
// 2022-03-11 03:00:45 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);

    vector<vector<char> > table(n, vector<char>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf(" %c", &table[i][j]);
        
    const int mov[4][2]={{0,1}, {1,0}, {-1,0}, {0,-1}};
    for(int h=0; h<2; h++)
    {
        vector<vector<int> > visited(n, vector<int>(n,0)), tmp(n, vector<int>(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(h==0) tmp[i][j]=table[i][j];
                else
                {
                    if(table[i][j]!='B') tmp[i][j]='B';
                    else tmp[i][j]='0'; 
                }

        queue<pair<int,int> > q;
        int cnt=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(visited[i][j]) continue;
                cnt++;
                q.push({i,j});
                while(!q.empty())
                {
                    int x=q.front().first, y=q.front().second;
                    q.pop();
                    if(visited[x][y]) continue;
                    else visited[x][y]=1;

                    for(int m=0; m<4; m++)
                    {
                        int nx=x+mov[m][0], ny=y+mov[m][1];
                        if(0<=nx and nx<n and 0<=ny and ny<n and tmp[nx][ny]==tmp[x][y])
                            q.push({nx, ny});
                    }
                }
            }
        printf("%d ", cnt);
    }
}

/*
    
*/