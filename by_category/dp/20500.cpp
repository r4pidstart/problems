// https://www.acmicpc.net/problem/20500
// 2023-08-19 00:11:38
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<vector<vector<long> > > dp(n+1, vector<vector<long > >(3, vector<long>(2)));

    dp[0][0][0]=1;
    for(int i=1; i<=n; i++)
        for(int j=0; j<3; j++)
        {
            dp[i][j][0]=(dp[i][j][0]+dp[i-1][(j-1+3)%3][0])%(int)(1e9+7); // append 1
            dp[i][j][0]=(dp[i][j][0]+dp[i-1][(j-1+3)%3][1])%(int)(1e9+7);

            dp[i][j][1]=(dp[i][j][1]+dp[i-1][(j-2+3)%3][1])%(int)(1e9+7); // append 5
            dp[i][j][1]=(dp[i][j][1]+dp[i-1][(j-2+3)%3][0])%(int)(1e9+7);
        }
    printf("%ld", dp[n][0][1]);
}

/*
    0+5(2) -> 2
    1 + 2 -> 0
    2 + 2 -> 0
*/