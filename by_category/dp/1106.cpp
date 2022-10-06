// https://www.acmicpc.net/problem/1106
// 2022-10-07 00:16:50 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int c,n; scanf("%d%d", &c, &n);
    vector<pair<int,int> > promotion(n+1);
    for(int i=1; i<=n; i++)
        scanf("%d%d", &promotion[i].first, &promotion[i].second);
    
    vector<vector<int> > dp(n+1, vector<int>(c+1, INT32_MAX/2));
    for(int i=1; i<=n; i++)
    {
        dp[i][0]=0;
        for(int j=1; j<=c; j++)
        {
            if(j<promotion[i].second) dp[i][j]=dp[i-1][j];
            else dp[i][j]=min(dp[i-1][j], dp[i][j-promotion[i].second]+promotion[i].first);
        }
        // n일때
        for(int j=c-1, l=max(0, c-promotion[i].second); j>=l; j--)
            dp[i][c]=min(dp[i][c], dp[i][j] + promotion[i].first);
    }
    printf("%d", dp[n][c]);
}

/*
    
*/