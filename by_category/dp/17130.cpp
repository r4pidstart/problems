// https://www.acmicpc.net/problem/17130
// 2023-07-02 10:04:59
#include"bits/stdc++.h"
using namespace std;

int ans(int x, int y, vector<vector<int> >& table)
{
    static vector<vector<int> > memo(table.size()+1, vector<int>(table[0].size()+1, -1));
    if(memo[x][y]!=-1) return memo[x][y];

    int ret=INT32_MIN;
    if(table[x][y]=='O') ret=0;
    if(table[x][y]=='R') ret=-1;
    
    const int way[3][2]={{0, 1}, {1, 1}, {-1, 1}};
    for(int w=0; w<3; w++)
    {
        int nx=x+way[w][0], ny=y+way[w][1];
        if(0<=nx and nx<table.size() and 0<=ny and ny<table[0].size() and table[nx][ny]!='#')
            ret=max(ret, ans(nx, ny, table)+(table[nx][ny]=='C'));
    }
    return memo[x][y]=ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    int x,y;
    vector<vector<int> > table(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            scanf(" %1c", &table[i][j]);
            if(table[i][j]=='R')
                x=i, y=j;
        }
    printf("%d", ans(x, y, table));
}

/*
    
*/