// https://www.acmicpc.net/problem/2573
// 2022-08-18 05:45:57 268ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > table(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &table[i][j]);
    
    int cnt=0;
    while(++cnt)
    {
        const int way[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<vector<int> > diff(n, vector<int>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(table[i][j])
                    for(int w=0; w<4; w++)
                    {
                        int nx=i+way[w][0], ny=j+way[w][1];
                        if(0<=nx and nx<n and 0<=ny and ny<m and !table[nx][ny])
                            diff[i][j]++;
                    }

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                table[i][j]=max(0, table[i][j]-diff[i][j]);
        
        int iceburg_cnt=0;
        vector<vector<int> > visited(n, vector<int>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(table[i][j] and !visited[i][j])
                {
                    queue<pair<int,int> > q;
                    q.push({i, j});
                    visited[i][j]++;
                    
                    iceburg_cnt++;
                    while(q.size())
                    {
                        int x=q.front().first, y=q.front().second;
                        q.pop();

                        for(int w=0; w<4; w++)
                        {
                            int nx=x+way[w][0], ny=y+way[w][1];
                            if(0<=nx and nx<n and 0<=ny and ny<m and !visited[nx][ny] and table[nx][ny])
                                q.push({nx, ny}), visited[nx][ny]++;
                        }          
                    }
                }
        
        if(iceburg_cnt == 0)
            return !printf("0");
        else if(iceburg_cnt != 1)
            return !printf("%d", cnt);
    }
}

/*
    
*/