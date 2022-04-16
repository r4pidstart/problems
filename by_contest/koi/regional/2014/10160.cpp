// https://www.acmicpc.net/problem/10160
// 
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<long long> dp(n+1);
    dp[0]=1;
    for(int i=0; i<4; i++)
        dp[i+1]=dp[i]*k;
    
    for(int i=4; i<n; i++)
        dp[i+1]=(dp[i] * k - (dp[i-4]*2 - (i-6 >= 0 ? dp[i-6] : 0)) + 2000000018) % 1000000009;
    printf("%lld", dp[n]);
}

/*
    
*/