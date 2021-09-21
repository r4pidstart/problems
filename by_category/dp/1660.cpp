// https://www.acmicpc.net/problem/1660
// 2021-09-21 23:17:59 100ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<long long> dp(n+1, INT32_MAX/2), count;
    dp[0]=0, dp[1]=1, count.push_back(1);
    long long tmp1=1, tmp2=1;
    count.reserve(10000);
    for(int i=2; i<=n; i++)
    {
        tmp1+=i;
        tmp2+=tmp1;
        if(tmp2 <= n) count.push_back(tmp2);
        for(int j : count)
            if(j <= i)
                dp[i]=min(dp[i], dp[i-j]+1);
    }
    printf("%lld", dp[n]);
}

/*
    
*/