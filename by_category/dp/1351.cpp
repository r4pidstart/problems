// https://www.acmicpc.net/problem/1351
// 2021-09-10 01:25:23 24ms
#include<bits/stdc++.h>
using namespace std;

long long n,p,q; 

vector<long long> memo(2000000, 0);
long long dp(long long n)
{
    if(n==0) return 1;
    if(n<2000000) if(memo[n]) return memo[n];
    long long ret=dp(floor(n/p))+dp(floor(n/q));
    if(n<2000000) memo[n]=ret;
    return ret;
}
int main(void)
{
    scanf("%lld%lld%lld", &n,&p,&q);
    printf("%lld", dp(n));
}

/*

*/