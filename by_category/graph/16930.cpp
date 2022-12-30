// https://www.acmicpc.net/problem/16930
// 2022-12-30 19:28:49
#include"bits/stdc++.h"
using namespace std;

int dfs(int x, int y, int ex, int ey, vector<vector<char> > &table)
{
    static int n=table.size(), m=table[0].size();
    static vector<vector<int> > visited(table.size(), vector<int>(table[0].size()));

    if(x==ex and y==ey)
        return 1;

    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    for(int w=0; w<4; w++)
    {
        int nx=x+way[w][0], ny=y+way[w][1];
        if(0<=nx and nx<n and 0<=ny and ny<m and table[nx][ny]=='.' and !visited[nx][ny])
        {
            visited[nx][ny]=1;
            if(dfs(nx, ny, ex, ey, table))
                return 1;
        }
    }
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    vector<vector<char> > table(n, vector<char>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &table[i][j]);
    
    int sx, sy, ex, ey;
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    vector<vector<int> > visited(n, vector<int>(m));

    // check
    if(!dfs(sx-1, sy-1, ex-1, ey-1, table))
        return !printf("-1");

    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    queue<pair<int, pair<int,int> > > q;
    q.push({0, {sx-1, sy-1}});
    visited[sx-1][sy-1]=1;
    while(q.size())
    {
        int c=q.front().first;
        int x=q.front().second.first, y=q.front().second.second;
        q.pop();

        if (x==ex-1 and y==ey-1)
            return !printf("%d", c);

        stack<pair<int, pair<int,int> > > stk;
        for(int w=0; w<4; w++)
        {
            for(int d=1; d<=k; d++)
            {
                int nx=x+way[w][0]*d, ny=y+way[w][1]*d;
                if(0<=nx and nx<n and 0<=ny and ny<m and table[nx][ny]=='.')
                {
                    if(!visited[nx][ny])
                    {
                        visited[nx][ny]=1;
                        stk.push({c+1, {nx, ny}});
                    }
                }
                else
                    break;
            }
        }
        while(stk.size())
        {
            q.push(stk.top());
            stk.pop();
        }
    }
    printf("-1");
}

/*
    
*/