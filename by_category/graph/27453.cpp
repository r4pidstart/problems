// https://www.acmicpc.net/problem/27453
// 2023-02-28 02:00:44  
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    vector<vector<int> > table(n, vector<int>(m));
    int x,y;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            scanf(" %c", &table[i][j]);
            if(table[i][j]=='S') x=i, y=j;
            if(isdigit(table[i][j])) table[i][j]-='0';
        }

    // x, y, dir, px, py, p1, p2, dist
    queue<tuple<int, int, int, int, int, int, int, int> > q;
    vector<vector<vector<int> > > visited(n, vector<vector<int> >(m, vector<int>(4)));
    visited[x][y][0]=1;
    q.push({x, y, 0, x, y, 0, 0, 0});
    
    while(q.size())
    {
        auto [x, y, dir, px, py, p1, p2, dist]=q.front();
        q.pop();

        if(table[x][y]=='H')
            return !printf("%d", dist);

        const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        for(int i=0; i<4; i++)
        {
            int nx=x+way[i][0], ny=y+way[i][1];
            if(0<=nx and nx<n and 0<=ny and ny<m and table[nx][ny] != 'X' and !visited[nx][ny][i])
                if((nx!=px or ny!=py) and (p1+p2 + table[nx][ny] <= k or table[nx][ny]=='H'))
                    visited[nx][ny][i]=1, q.push({nx, ny, i, x, y, p2, table[nx][ny], dist+1});
        }
    }
    printf("-1");
}

/*
    
*/