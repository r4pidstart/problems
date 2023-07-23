// https://www.acmicpc.net/problem/1245
// 2023-07-24 00:23:44
#include"bits/stdc++.h"
using namespace std;

int check(int x, int y, vector<vector<int> >& table, vector<vector<int> >& visited)
{
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

    int ret=1;
    visited[x][y]=1;

    for(int w=0; w<8; w++)
    {
        int nx=x+way[w][0], ny=y+way[w][1];
        if(0<=nx and nx<table.size() and 0<=ny and ny<table[0].size())
        {
            if(table[x][y]<table[nx][ny]) ret=0;
            if(!visited[nx][ny] and table[x][y]==table[nx][ny]) ret=min(ret, check(nx, ny, table, visited));
        }
    }
    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > table(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &table[i][j]);
    
    int ans_cnt=0;
    vector<vector<int> > visited(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!visited[i][j] and table[i][j])
                ans_cnt+=check(i, j, table, visited);

    printf("%d", ans_cnt);
}

/*
    
*/