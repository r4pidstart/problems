// https://www.acmicpc.net/problem/10978
// 2023-11-16 02:41:41
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    vector<long> dp(21);
    dp[2]=1;
    for(int i=3; i<21; i++)
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    while(t--)
    {
        int n; scanf("%d", &n);
        printf("%ld\n", dp[n]);
    }
}

/*
    
*/