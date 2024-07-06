// https://www.acmicpc.net/problem/15791
// 2024-07-03 10:09:17
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

template<class T>
tuple<T, T, T> xgcd(T a, T b)
{
    if(b==0) return {a, 1, 0};
    
    auto [gcd,x,y]=xgcd(b, a%b);
    return {gcd, y, x-a/b*y};
}

template<class T>
T inv_mod(T n, T mod)
{
    auto [g,x,y]=xgcd(n, mod);
    return g==1 ? (x+mod)%mod:-1;
}

long factorial(long n, int mod)
{
    if(n==0)
        return 1;
    return n*factorial(n-1, mod)%mod;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,m; cin >> n >> m;
    int mod=1e9+7;
    long nfac=factorial(n, mod), mfac=factorial(m, mod), nmmfac=factorial(n-m, mod);
    cout << nfac*inv_mod(mfac, long(mod))%mod*inv_mod(nmmfac, long(mod))%mod; 
}

/*
    
*/