// https://www.acmicpc.net/problem/10164
// 2021-08-24 04:22:50 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<vector<int> > dp(n+1, vector<int>(m+1,0));
    int k; scanf("%d", &k);

    dp[1][1]=1;
    if(k==0)
    {
        // 1 to n*m
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                dp[i][j]+=dp[i-1][j]+dp[i][j-1];
    }
    else
    {
        int kx=k/m+1, ky=k%m;
        if(ky==0) ky=m, kx--;
        // 1 to k
        for(int i=1; i<=kx; i++)
            for(int j=1; j<=ky; j++)
                dp[i][j]+=dp[i-1][j]+dp[i][j-1];
        dp[kx][ky]=0;

        // k to n*m
        for(int i=kx; i<=n; i++)
            for(int j=ky; j<=m; j++)
                dp[i][j]+=dp[i-1][j]+dp[i][j-1];
    }
    printf("%d", dp[n][m]);
}

/*

*/