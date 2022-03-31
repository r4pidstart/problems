// https://www.acmicpc.net/problem/1926
// 2022-04-01 03:50:16 36ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int m,n; scanf("%d%d", &n, &m);
    vector<vector<int> > table(n, vector<int>(m, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &table[i][j]);


    // bfs
    const int mov[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    vector<int> area;
    vector<vector<int> > visited(n, vector<int>(m));
    queue<pair<int,int> > q;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(!table[i][j] or visited[i][j]) continue;
            
            q.push({i,j});

            int tmp=0;
            while(!q.empty())
            {
                auto [x,y]=q.front(); q.pop();
                if(visited[x][y]) continue;
                visited[x][y]=1;

                tmp++;
                for(int w=0; w<4; w++)
                {
                    int nx=x+mov[w][0], ny=y+mov[w][1];
                    if(0<=nx and nx<n and 0<=ny and ny<m and table[nx][ny])
                        q.push({nx, ny});
                }
            }
            area.push_back(tmp);
        }

    printf("%d\n", area.size());
    if(area.size()==0) return !printf("0");
    sort(area.begin(), area.end(), greater<int>());
    printf("%d ", area[0]);
}

/*
    
*/