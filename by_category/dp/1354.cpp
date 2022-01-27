// https://www.acmicpc.net/problem/1354
// 2022-01-27 23:31:26 4164ms
#include<bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> memo;
long long dp(long long i, long long p, long long q, long long x, long long y)
{
    if(i<=0) return 1;
    if(memo.find(i) != memo.end()) return memo[i];
    else return memo[i]=dp(i/p - x, p, q, x, y)+dp(i/q - y, p, q, x, y);
}

int main(void)
{
    long long n,p,q,x,y; scanf("%lld%lld%lld%lld%lld", &n,&p,&q,&x,&y);
    printf("%lld", dp(n, p, q, x, y));
}

/*
    
*/