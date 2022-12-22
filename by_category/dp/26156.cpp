// https://www.acmicpc.net/problem/26156
// 2022-12-22 01:11:29 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    cout.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<long> > dp(n+1, vector<long>(5));
    string s; cin >> s;

    reverse(s.begin(), s.end());

    dp[0][0]=1;
    const int mod=1e9+7;
    for(int i=1; i<=n; i++)
    {
        // 안 고르는 경우
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-1][2];
        dp[i][3] = dp[i-1][3];
        dp[i][4] = dp[i-1][4];

        // 고르는 경우
        dp[i][4] += dp[i-1][4], dp[i][4] %= mod;

        if(s[i-1] == 'R')
            dp[i][4] += dp[i-1][3], dp[i][4] %= mod;
        else if(s[i-1] == 'O')
            dp[i][3] += dp[i-1][2], dp[i][3] %= mod;
        else if(s[i-1] == 'C')
            dp[i][2] += dp[i-1][1], dp[i][2] %= mod;
        else if(s[i-1] == 'K')
            dp[i][1] += dp[i-1][0], dp[i][1] %= mod;
    }
    printf("%ld", dp[n][4]);
}

/*
    
*/