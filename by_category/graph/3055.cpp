// https://www.acmicpc.net/problem/3055
// 2022-09-23 03:12:53 4ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<char> > table(n, vector<char>(m)), visited(n, vector<char>(m));
    queue<pair<pair<int, int>,int> > q;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            scanf(" %c", &table[i][j]);
            if(table[i][j] == 'S') q.push({{i, j}, 0});
        }
    
    int prev=-1;
    const int way[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
    while(q.size())
    {
        pair<int, int> now=q.front().first;
        int now_t=q.front().second;
        q.pop();
        
        if(now_t != prev)
        {
            queue<pair<int,int> > q;
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    if(table[i][j] == '*')
                        q.push({i,j});
            
            while(q.size())
            {
                int i=q.front().first, j=q.front().second;
                q.pop();
                for(int k=0; k<4; k++)
                {
                    int nx=i+way[k][0], ny=j+way[k][1];
                    if(0<=nx and nx<n and 0<=ny and ny<m and table[nx][ny]=='.')
                        table[nx][ny]='*';
                }
            }
            prev=now_t;
        }

        if(table[now.first][now.second] == 'D')
            return !printf("%d", now_t);
        
        for(int k=0; k<4; k++)
        {
            int nx=now.first+way[k][0], ny=now.second+way[k][1];
            if(0<=nx and nx<n and 0<=ny and ny<m and (table[nx][ny]=='.' or table[nx][ny]=='D') and !visited[nx][ny])
                visited[nx][ny]=1, q.push({{nx, ny}, now_t+1});
        }
    }
    printf("KAKTUS");
}

/*
    
*/