// https://www.acmicpc.net/problem/14495
// 2021-09-14 03:47:03 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<long long> dp(117);
    dp[1]=dp[2]=dp[3]=1;
    for(int i=4; i<=n; i++)
        dp[i]=dp[i-1]+dp[i-3];
    printf("%lld", dp[n]);
}

/*

*/