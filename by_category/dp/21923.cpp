// https://www.acmicpc.net/problem/21923
// 2022-09-27 00:25:55 168ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > table(n, vector<int>(m));
    for(int i=n-1; i>=0; i--)
        for(int j=0; j<m; j++)
            scanf("%d", &table[i][j]);

    // 올라가자
    vector<vector<long> > dp_up(n+1, vector<long>(m+1, INT32_MIN/2));
    dp_up[0][1]=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            dp_up[i][j] = max(dp_up[i-1][j], dp_up[i][j-1])+table[i-1][j-1];

    // 내려가자
    vector<vector<long> > dp_down(n+1, vector<long>(m+1, INT32_MIN/2));
    for(int i=n-1; i>=0; i--)
        for(int j=1; j<=m; j++)
            dp_down[i][j] = max({dp_up[i+1][j], dp_down[i+1][j], dp_down[i][j-1]}) + table[i][j-1];
    printf("%ld", dp_down[0][m]);
}
/*
    
*/