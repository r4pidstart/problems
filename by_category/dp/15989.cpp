// https://www.acmicpc.net/problem/15989
// 2021-09-12 00:56:56 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    vector<vector<int> > dp(10001, vector<int>(3,0));
    dp[1][0]=1, dp[2][0]=1, dp[2][1]=1, dp[3][0]=1, dp[3][1]=1, dp[3][2]=1;
    for(int i=4; i<=10000; i++)
        dp[i][0]=1, dp[i][1]=dp[i-2][0]+dp[i-2][1], dp[i][2]=dp[i-3][0]+dp[i-3][1]+dp[i-3][2];

    while(t--)
    {
        int n; scanf("%d", &n);
        printf("%d\n", dp[n][0]+dp[n][1]+dp[n][2]);
    }
}

/*

*/