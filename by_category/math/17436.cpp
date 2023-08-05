// https://www.acmicpc.net/problem/17436
// 2023-08-06 01:15:58
#include"bits/stdc++.h"
using namespace std;

long ans(int idx, long target, int cnt, int sel, vector<long>& primes, long n)
{
    if(idx==primes.size()) return 0;

    long ret=0;
    if(sel)
    {
        if(cnt&1) ret+=n/target;
        else ret-=n/target;
    }
    ret+=ans(idx+1, lcm(target, primes[idx]), cnt+1, 1, primes, n);
    ret+=ans(idx+1, target, cnt, 0, primes, n);

    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    long n,m; scanf("%ld%ld", &n, &m);
    vector<long> primes(n+1);
    for(int i=0; i<n; i++)
        scanf("%ld", &primes[i]);

    printf("%ld", ans(0, 1, 0, 0, primes, m));
}

/*
    
*/