// https://www.acmicpc.net/problem/14916
// 2021-09-03 22:49:18 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> dp(n+1, INT32_MAX/2);
    dp[0]=0;
    for(int i=1; i<=n; i++)
    {
        if(i-2 >= 0) dp[i]=min(dp[i], dp[i-2]+1);
        if(i-5 >= 0) dp[i]=min(dp[i], dp[i-5]+1);
    }
    if(dp[n]==INT32_MAX/2) printf("-1");
    else printf("%d", dp[n]);
}

/*

*/