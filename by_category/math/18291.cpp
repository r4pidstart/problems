// https://www.acmicpc.net/problem/18291
// 2022-06-06 03:37:45 0ms
#include"bits/stdc++.h"
using namespace std;

long long modpow(int base, int expo)
{
    if(expo == 0) return 1;
    if(expo == 1) return base;
    
    long long ret = modpow(base, expo/2) * modpow(base, expo/2) % (int)(1e9 + 7);
    if(expo&1) ret = ret * base % (int)(1e9 + 7);
    return ret;
}

int main(void)
{
    // ans : 2^(max(0, n-2))
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        printf("%d\n", modpow(2, max(0, n-2)));
    }
}

/*
    
*/