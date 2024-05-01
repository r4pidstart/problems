// https://www.acmicpc.net/problem/31779
// 2024-04-30 15:54:44
#include"bits/stdc++.h"
using namespace std;

long dfs(int x, int y, vector<vector<long> >& table, vector<vector<long> >& target, const vector<vector<int> >& volcano)
{
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    static vector<vector<int> > visited(table.size(), vector<int>(table[0].size()));

    int n=table.size(), m=table[0].size();
    visited[x][y]=1;

    for(int w=0; w<4; w++)
    {
        int nx=x+way[w][0], ny=y+way[w][1];
        if(0<=nx and nx<n and 0<=ny and ny<m and !visited[nx][ny] and !volcano[nx][ny])
        {
            table[nx][ny]+=target[x][y]-table[x][y];
            table[x][y]+=target[x][y]-table[x][y];

            table[x][y]+=dfs(nx, ny, table, target, volcano);
        }
    }
    long tmp=target[x][y]-table[x][y];
    table[x][y]=target[x][y];
    return tmp;
}

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    vector<vector<long> > table(n, vector<long>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%ld", &table[i][j]);
    
    vector<vector<long> > target(n, vector<long>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%ld", &target[i][j]);

    vector<vector<int> > volcano(n, vector<int>(m));
    while(k--)
    {
        int a,b; scanf("%d%d", &a, &b);
        volcano[a-1][b-1]=1;
        if(target[a-1][b-1] != table[a-1][b-1])
            return !printf("No");
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(table[i][j] != target[i][j] and !volcano[i][j] and dfs(i, j, table, target, volcano))
                return !printf("No");
        }

    printf("Yes");
}

/*
    
*/