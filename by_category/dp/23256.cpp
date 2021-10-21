// https://www.acmicpc.net/problem/23256
// 2021-10-21 23:33:04 80ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    const int MOD=1e9+7;
    vector<vector<long long> > dp(1000001, vector<long long>(2, 0));
    // dp[n][0] -> 마지막을 뺄 수 있는, dp[n][1] -> 못 빼는
    dp[1][0]=3, dp[1][1]=4;
    for(int i=2; i<1000001; i++)
    {
        dp[i][0]=( dp[i-1][0]*3 + dp[i-1][1]*1 ) % MOD;
        dp[i][1]=( dp[i-1][0]*4 + dp[i-1][1]*2 ) % MOD;
    }

    int t; scanf("%d",&t);
    while(t--)
    {
        int n; scanf("%d", &n);
        printf("%lld\n", (dp[n][1]+dp[n][0])%MOD);
    }
}

/*
    
*/