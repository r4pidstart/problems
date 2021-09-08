// https://www.acmicpc.net/problem/11058
// 2021-09-09 02:21:16 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<long long> dp(n+1, 0);
    dp[1]=1;
    for(int i=2; i<=n; i++)
    {
        dp[i]=dp[i-1]+1;
        // 다시 붙여넣는 경우
        for(int j=0; i-j-3>=0; j++)
            dp[i]=max(dp[i], dp[i-j-3]*(j+2));
    }
    printf("%lld", dp[n]);
}

/*

*/