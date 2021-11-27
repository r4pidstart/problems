// https://www.acmicpc.net/problem/8394
// 2021-11-27 23:53:31 92ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<long long> dp(n+1);
    dp[0]=1, dp[1]=1;
    for(int i=2; i<=n; i++)
        dp[i]=(dp[i-2]+dp[i-1])%10;
    printf("%d", dp[n]);
}

/*
    
*/