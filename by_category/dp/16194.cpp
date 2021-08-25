// https://www.acmicpc.net/problem/16194
// 2021-08-26 05:52:18 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> price(n+1, 0), dp(n+1, INT32_MAX/2);
    for(int i=0; i<n; i++)
        scanf("%d", &price[i+1]);

    dp[0]=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            dp[i]=min(dp[i-j]+price[j], dp[i]);
    printf("%d", dp[n]);
}

/*

*/