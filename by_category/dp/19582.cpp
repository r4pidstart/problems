// https://www.acmicpc.net/problem/19582
// 2023-10-20 02:23:23
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);

    vector<vector<long> > dp(n+1, vector<long>(2, LLONG_MAX/2));

    dp[0][0]=0;

    for(int i=1; i<=n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        // participate this
        if(dp[i-1][0] != LLONG_MAX/2 and dp[i-1][0] <= a)
            dp[i][0]=dp[i-1][0]+b;
        if(dp[i-1][1] != LLONG_MAX/2 and dp[i-1][1] <= a)
            dp[i][1]=dp[i-1][1]+b;
        // skip this
        if(dp[i-1][0] != LLONG_MAX/2)
            dp[i][1]=min(dp[i][1], dp[i-1][0]);
    }
    if(dp[n][0]!=LLONG_MAX/2 or dp[n][1]!=LLONG_MAX/2)
        printf("Kkeo-eok");
    else
        printf("Zzz");
}

/*
    
*/