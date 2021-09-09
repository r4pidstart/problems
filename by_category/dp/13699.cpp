// https://www.acmicpc.net/problem/13699
// 2021-09-10 02:06:53 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<long long> dp(n+1, 0);
    dp[0]=1;
    if(n>0) dp[1]=1;

    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<i; j++)
            dp[i]+=dp[j]*dp[i-j-1];
    }
    printf("%lld", dp[n]);
}

/*

*/