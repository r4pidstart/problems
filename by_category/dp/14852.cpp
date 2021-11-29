// https://www.acmicpc.net/problem/14852
// 2021-11-29 23:35:22 16ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<long long> dp{1,2,7}, dp2{2,6,20};
    dp.resize(n+1), dp2.resize(n+1);
    for(int i=3; i<=n; i++)
    {
        dp[i]=(dp[i-1]*2 + dp[i-2]*3 + dp2[i-3])%(int)(1e9+7);
        dp2[i]=(dp2[i-1]+dp[i]*2)%(int)(1e9+7);
    }
    printf("%d", dp[n]);
}

/*
    
*/