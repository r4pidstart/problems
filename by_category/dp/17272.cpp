// https://www.acmicpc.net/problem/17272
// 2024-04-24 14:06:39
#include"bits/stdc++.h"
using namespace std;

long solution(long n, int m)
{
    static map<long, long> dp;
    if(n<0) return 0;
    if(n<m) return 1;
    if(n==m) return 2;

    if(dp.find(n) != dp.end())
        return dp[n];

    long ret=(solution(n/2, m)*solution(n-n/2, m))%1'000'000'007;
    
    for(int i=1; i<m; i++)
        ret=(ret+solution(n/2-i, m)*solution(n-n/2-m+i, m))%1'000'000'007;
    return dp[n]=ret;
}

int main(void)
{
    long n,m; scanf("%ld%ld", &n, &m);
    printf("%ld", solution(n, m));
}

/*
    
*/