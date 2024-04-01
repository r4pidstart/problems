// https://www.acmicpc.net/problem/2589
// 2024-03-30 22:58:56
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);

    vector<vector<char> > table(n, vector<char>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &table[i][j]);

    int ans=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(table[i][j]!='L') continue;
            queue<pair<int, int> > q;
            q.push({i, j});
            vector<vector<int> > visited(n, vector<int>(m, INT32_MAX/2));
            visited[i][j]=0;

            while(q.size())
            {
                auto [x, y]=q.front();
                q.pop();

                for(int w=0; w<4; w++)
                {
                    int nx=x+way[w][0], ny=y+way[w][1];
                    if(0<=nx and nx<n and 0<=ny and ny<m and visited[nx][ny]==INT32_MAX/2 and table[nx][ny]=='L')
                        q.push({nx, ny}), visited[nx][ny]=visited[x][y]+1;
                }
            }
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    if(visited[i][j] != INT32_MAX/2)
                        ans=max(ans, visited[i][j]);
        }
    printf("%d", ans);
}

/*
    
*/