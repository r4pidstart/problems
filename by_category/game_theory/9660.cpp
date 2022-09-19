// https://www.acmicpc.net/problem/1106
// 2022-09-20 02:04:09
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    // vector<int> dp(1000, 0);
    // dp[0]=1;
    // for(int i=1; i<1000; i++)
    // {
    //     if(i>=1 and !dp[i-1]) dp[i]=1;
    //     if(i>=3 and !dp[i-3]) dp[i]=1;
    //     if(i>=4 and !dp[i-4]) dp[i]=1;
    // }
    // for(auto i : dp)
    // printf("%d ", i);
    long n; scanf("%ld", &n);
    vector<int> ans{0, 1, 0, 1, 1, 1, 1};
    printf("%s", ans[n%7] ? "SK":"CY");
}

/*
    
*/