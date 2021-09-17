// https://www.acmicpc.net/problem/1563
// 2021-09-18 03:55:39 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    const int mod=1000000;
    int n; scanf("%d", &n);
    vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(2, vector<int>(3, 0)));
    // dp[i][j][k] : i일동안 j번 지각하고, k번 연속으로 결석 한 경우의 수.
    dp[1][0][0]=dp[1][1][0]=dp[1][0][1]=1; // O L A
    for(int i=1; i<n; i++)
    {
        dp[i+1][0][0]=(dp[i][0][0]+dp[i][0][1]+dp[i][0][2])%mod; // +O
        dp[i+1][0][1]=dp[i][0][0]; // +A
        dp[i+1][0][2]=dp[i][0][1]; // +A
        dp[i+1][1][0]=(dp[i+1][0][0]+dp[i][1][0]+dp[i][1][1]+dp[i][1][2])%mod; // +L, +O
        dp[i+1][1][1]=dp[i][1][0]; // +A 
        dp[i+1][1][2]=dp[i][1][1]; // +A
    }
    printf("%d", (accumulate(dp[n][0].begin(), dp[n][0].end(), 0)+accumulate(dp[n][1].begin(), dp[n][1].end(), 0))%mod);
}

/*
    
*/