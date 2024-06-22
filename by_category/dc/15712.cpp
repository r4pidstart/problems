// https://www.acmicpc.net/problem/15712
// 2024-06-22 21:23:32
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

long powmod(long a, long b, long mod)
{
    if(b==0)
        return 1;

    long tmp=powmod(a, b/2, mod);
    if(b&1) return tmp*tmp%mod*a%mod;
    return tmp*tmp%mod;
}

long solution(long a, long r, long n, long mod)
{
    if(n==1)
        return a%mod;
    
    // 짝수항만의 합 구하기
    long tmp=solution(a, r*r%mod, n/2, mod);
    
    long ret=(tmp+(tmp*r)%mod)%mod;
    if(n&1) ret=(ret+a*powmod(r, n-1, mod)%mod)%mod;

#ifdef LOCAL
    cout << format("{} {} {} {}\n", a, r, n, tmp);
#endif
    return ret;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    long a,r,n,mod; cin >> a >> r >> n >> mod;
    cout << solution(a, r, n, mod);
}

/*
    a + ar + ar^2 + ar^3 + ar^4 + ... + ar^n-1

    ar^0+ar^2+ar^4 .. 
    ar^1+ar^3+ar^5 .. -> r(ar^0+ar^2+ar^4) -> r이 제곱이 되는 새로운 등비수열
*/