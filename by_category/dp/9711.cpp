// https://www.acmicpc.net/problem/9711
// 2022-08-27 01:35:46 620ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    for(int T=1; T<=t; T++)
    {
        int a,b; scanf("%d%d", &a, &b);
        vector<long> dp(max(2, a+1));
        dp[0]=dp[1]=1%b;
        for(int i=2; i<a+1; i++)
            dp[i]=(dp[i-1]+dp[i-2])%b;
        printf("Case #%d: %ld\n", T, dp[a-1]);
    }
}

/*
    
*/