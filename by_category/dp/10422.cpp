// https://www.acmicpc.net/problem/10422
// 2021-09-16 03:15:24 64ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    const int MOD=1e9+7;
    vector<vector<int> > dp(5001, vector<int>(2501,0));
    // dp[i][j] : i길이의, j개의 괄호가 닫히지 않은 문자열의 갯수
    dp[1][1]=1;
    for(int i=2; i<=5000; i++)
        for(int j=0; j<=2500; j++)
        {
            if(j==0) dp[i][0]=dp[i-1][1];
            else if(j==2500) dp[i][2500]=dp[i-1][2499];
            else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%MOD;
        }
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        printf("%d\n", dp[n][0]);
    }
}

/*

*/