// https://www.acmicpc.net/problem/14442
// 2021-12-23 00:09:05 824ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n,&m,&k);
    vector<vector<int> > table(n,vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d", &table[i][j]);
    
    // bfs
    const int way[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<vector<int> > > visited(n, vector<vector<int> >(m,vector<int>(k+1,0)));
    queue<pair<pair<int,int>, pair<int,int> > > q;
    q.push({{0,0},{1,k}});

    while(!q.empty())
    {
        auto now=q.front(); q.pop();
        if(now.first.first==n-1 and now.first.second==m-1) 
            return !printf("%d", now.second.first);
        
        if(visited[now.first.first][now.first.second][now.second.second]) continue;
        visited[now.first.first][now.first.second][now.second.second]=now.second.first;

        for(int i=0; i<4; i++)
        {
            int nx=now.first.first+way[i][0], ny=now.first.second+way[i][1];
            if(0<=nx and nx<n and 0<=ny and ny<m)
            {
                if(table[nx][ny])
                {
                    if(now.second.second)
                        if(!visited[nx][ny][now.second.second-1]) 
                            q.push({{nx,ny},{now.second.first+1, now.second.second-1}});
                } 
                else
                    if(!visited[nx][ny][now.second.second])
                        q.push({{nx,ny},{now.second.first+1, now.second.second}});
            }
        }
    }
    printf("-1");
}

/*
    
*/