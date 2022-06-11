// https://www.acmicpc.net/problem/17086
// 2022-06-12 04:02:27 340ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > table(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &table[i][j]);
    
    int ans=0;
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            queue<pair<pair<int, int>, int> > q;
            vector<vector<int> > visited(n, vector<int>(m));
            q.push({{i, j}, 0});
            while(q.size())
            {
                auto now=q.front().first; int cnt=q.front().second;
                q.pop();
                
                if(visited[now.first][now.second]) continue;
                else visited[now.first][now.second]++;

                if(table[now.first][now.second])
                {
                    ans=max(ans, cnt);
                    break;
                }

                for(int w=0; w<8; w++)
                {
                    int nx=now.first+way[w][0], ny=now.second+way[w][1];
                    if(0<=nx and nx<n and 0<=ny and ny<m)
                        q.push({{nx, ny}, cnt+1});
                }
            }
        }
    printf("%d", ans);
}

/*
    
*/