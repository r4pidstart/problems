// https://www.acmicpc.net/problem/7894
// 2023-11-13 21:53:10
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    vector<double> dp(10000001);
    for(int i=1; i<=10000000; i++)
        dp[i]=dp[i-1]+log10(i);
    while(t--)
    {
        int n; scanf("%d", &n);
        printf("%d\n", (int)dp[n]+1);
    }
}

/*
    
*/