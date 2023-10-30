// https://www.acmicpc.net/problem/16441
// 2023-10-30 20:09:40
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<char> > table(n, vector<char>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &table[i][j]);
    
    queue<tuple<int, int> > q;
    vector<vector<int> > visited(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(table[i][j]=='W')
                q.push({i, j}), visited[i][j]=1;

    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    while(q.size())
    {
        auto [x, y]=q.front();
        q.pop();

        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(0<=nx and nx<n and 0<=ny and ny<m)
            {
                if(table[nx][ny]=='+')
                {
                    while(table[nx][ny] == '+')
                        nx+=way[w][0], ny+=way[w][1];
                    if(table[nx][ny] == '#')
                        nx-=way[w][0], ny-=way[w][1];
                }
                if(!visited[nx][ny] and table[nx][ny]!='#')
                    q.push({nx, ny}), visited[nx][ny]=1;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(table[i][j]=='.' and !visited[i][j])
                printf("P");
            else printf("%c", table[i][j]);
        }
        printf("\n");
    }

}

/*
    
*/