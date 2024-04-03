// https://www.acmicpc.net/problem/12946
// 2024-03-29 00:06:28
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > table(n+1, vector<int>(n+1));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            scanf(" %c", &table[i][j]);
            table[i][j]=(table[i][j]=='-' ? 0:1);
        }
    
    vector<vector<int> > color(n+1, vector<int>(n+1, -1));
    
    int cnt=0;
    const int way[6][2]={{-1, 0}, {-1, +1}, {0, -1}, {0, +1}, {+1, -1}, {+1, 0},};
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(table[i][j]==1)
            {
                cnt=max(cnt, 1);
                queue<pair<int, int> > q;
                q.push({i, j});
                color[i][j]=0;
                table[i][j]=2;
                
                while(q.size())
                {
                    auto [x, y]=q.front();
                    q.pop();

                    int nc=color[x][y]^1;

                    for(int w=0; w<6; w++)
                    {
                        int nx=x+way[w][0], ny=y+way[w][1];
                        if(0<=nx and nx<n and 0<=ny and ny<n and table[nx][ny])
                        {
                            // if already visited
                            if(table[nx][ny]==2 and color[nx][ny]!=nc)
                                cnt=3;
                            else if(table[nx][ny]==1)
                                color[nx][ny]=nc, table[nx][ny]=2, q.push({nx, ny}), cnt=max(cnt, 2);
                        }
                    }
                }

            }
        }
    
    printf("%d", cnt);
}

/*
    
*/