// https://www.acmicpc.net/problem/9659
// 2022-09-28 01:57:59
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    long n; scanf("%ld", &n);
    // vector<int> dp(10000);
    // dp[1]=1;
    // dp[3]=1;
    // for(int i=4; i<n; i++)
    // {
    //     if(dp[i-1] and dp[i-3]) dp[i]=0;
    //     else dp[i]=1;
    //     printf("%d : %d\n", i, dp[i]);
    // }
    printf("%s", n&1 ? "SK":"CY");
}

/*
    
*/