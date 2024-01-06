// https://www.acmicpc.net/problem/27728
// 2024-01-06 02:57:19
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,q; scanf("%d%d", &n, &q);
    vector<vector<int> > table(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &table[i][j]);
    
    vector<vector<int> > psum(n, vector<int>(n+1));
    for(int i=0; i<n; i++)
        for(int j=1; j<=n; j++)
            psum[i][j]=psum[i][j-1]+table[i][j-1];

    vector<vector<int> > dp(n+1, vector<int>(n+1));
    dp[0].assign(n+1, INT32_MAX/2);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            dp[i][j]=min(dp[i-1][j], psum[i-1][n]-psum[i-1][j-1]);

    while(q--)
    {
        int x,y,l; scanf("%d%d%d", &x, &y, &l);
        x--;
        int ans=psum[x][n]-psum[x][y-1];
        for(int i=y; i<=n; i++)
            ans=min(ans, psum[x][i-1]-psum[x][y-1]+dp[x-l+1][i]);   
        printf("%d\n", ans);   
    }
}  

/*
    
*/