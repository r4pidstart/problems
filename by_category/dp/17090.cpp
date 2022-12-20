// https://www.acmicpc.net/problem/17090
// 2022-12-21 01:15:01
#include"bits/stdc++.h"
using namespace std;

int check(int x, int y, vector<vector<char> >& table)
{
    static vector<vector<int> > dp(table.size(), vector<int>(table[0].size(), -1));

    if(dp[x][y] != -1)
        return dp[x][y];
    
    dp[x][y]=0;

    const int way[26][2]={['U'-'A'] = {-1, 0}, ['R'-'A'] = {0, +1}, ['D'-'A'] = {+1, 0}, ['L'-'A'] = {0, -1}};
    int nx=x+way[table[x][y]-'A'][0], ny=y+way[table[x][y]-'A'][1];

    if(0<=nx and nx<table.size() and 0<=ny and ny<table[0].size())
        return dp[x][y]=check(nx, ny, table);
    else
        return dp[x][y]=1;
}
int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);

    vector<vector<char> > table(n, vector<char>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &table[i][j]);
    
    int ans=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            ans+=check(i, j, table);
    printf("%d", ans);
}

/*
    
*/