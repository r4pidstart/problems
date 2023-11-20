// https://www.acmicpc.net/problem/14578
// 2023-11-20 00:52:29
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    
    vector<long> dp(n+1);
    dp[1]=0, dp[2]=1;
    for(int i=3; i<=n; i++)
        dp[i]=((i-1)*(dp[i-1]+dp[i-2]))%1'000'000'007;
    
    long factorial=1;
    for(int i=2; i<=n; i++)
        factorial=factorial*i%1'000'000'007;
    
    printf("%d", (int)(dp[n]*factorial%1'000'000'007));
}

/*
    
*/