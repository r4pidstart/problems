// https://www.acmicpc.net/problem/15990
// 2021-08-26 05:46:01 12ms
#include<bits/stdc++.h>
using namespace std;

#define MOD 1'000'000'009
int main(void)
{
    int t; scanf("%d", &t);
    vector<vector<int> > dp(100001,vector<int>(3,0));
    dp[0][0]=1; dp[1][0]=1; dp[2][1]=1;
    for(int i=3; i<100001; i++)
    {
        dp[i][0]=(dp[i-1][1]+dp[i-1][2])%MOD;
        dp[i][1]=(dp[i-2][0]+dp[i-2][2])%MOD;
        dp[i][2]=(dp[i-3][0]+dp[i-3][1])%MOD;
    }
    while(t--)
    {
        int a; scanf("%d", &a);
        printf("%d\n", (((dp[a][0]+dp[a][1])%MOD)+dp[a][2])%MOD);
    }
    
}

/*

*/