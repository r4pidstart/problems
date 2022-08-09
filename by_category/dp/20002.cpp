// https://www.acmicpc.net/problem/20002
// 2022-08-10 04:52:21
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > arr(n, vector<int>(n)), dp(n+1, vector<int>(n+1));

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &arr[i][j]);

    for(int i=1; i<n+1; i++)
        for(int j=1; j<n+1; j++)
            dp[i][j]=-dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1] + arr[i-1][j-1];
    
    int ans=INT32_MIN;
    for(int i=1; i<n+1; i++)
        for(int j=1; j<n+1; j++)
            for(int k=0; i+k<n+1 && j+k<n+1; k++)
            {
                ans=max(ans, dp[i+k][j+k] - dp[i-1][j+k] - dp[i+k][j-1] + dp[i-1][j-1]);
            }

    printf("%d", ans);
}

/*
    
*/