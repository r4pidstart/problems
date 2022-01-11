// https://www.acmicpc.net/problem/1947
// 2022-01-12 03:04:58 12ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<long long> dp(n+1);
    dp[1]=0, dp[2]=1;
    // 교란순열
    for(int i=3; i<=n; i++) 
        dp[i]=(i-1)*(dp[i-1]+dp[i-2])%1'000'000'000;
    printf("%lld", dp[n]);
}

/*
    
*/