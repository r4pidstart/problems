// https://www.acmicpc.net/problem/14940
// 2022-07-22 22:41:05 60ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > table(n, vector<int>(m));
    
    int startx, starty;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            scanf("%d", &table[i][j]);
            if(table[i][j] == 2)
                startx=i, starty=j;   
        }
    
    vector<vector<int> > dist(n, vector<int>(m));
    queue<pair<int, pair<int,int> > > q;
    q.push({0, {startx, starty}});

    const int way[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
    while(q.size())
    {
        int nowx=q.front().second.first, nowy=q.front().second.second, cnt=q.front().first;
        q.pop();

        for(int w=0; w<4; w++)
        {
            int nx=nowx+way[w][0], ny=nowy+way[w][1];
            if(0<=nx and nx<n and 0<=ny and ny<m)
            {
                if(!dist[nx][ny] and table[nx][ny]==1)
                    dist[nx][ny]=cnt+1, q.push({cnt+1, {nx, ny}});
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(table[i][j]==1 and !dist[i][j]) printf("-1 ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}