// https://www.acmicpc.net/problem/17212
// 2022-10-21 01:37:06 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> dp{0, 1, 1, 2, 2, 1, 2, 1};
    dp.resize(n+1);
    for(int i=8; i<=n; i++)
        dp[i]=min({dp[i-1]+1, dp[i-2]+1, dp[i-5]+1, dp[i-7]+1});
    printf("%d", dp[n]);
}

/*
    
*/