// https://www.acmicpc.net/problem/26008
// 2024-06-19 23:13:18
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

long powmod(int n, int m)
{
    if(m==0)
        return 1;

    long tmp=powmod(n, m/2);
    if(m&1)
        return tmp*tmp%int(1e9+7)*n%int(1e9+7);
    return tmp*tmp%int(1e9+7);
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,m,a; cin >> n >> m >> a;
    cout << powmod(m, n-1);
}

/*

*/