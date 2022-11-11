// https://www.acmicpc.net/problem/13172
// 2022-11-12 00:41:03
#include"bits/stdc++.h"
using namespace std;
const int mod=1'000'000'007;

long powmod(int a, int b)
{
    if(b==0) return 1;
    else if(b==1) return a;
    else if(b&1) return powmod(a, b-1)*a%mod;

    long tmp=powmod(a, b/2);
    return tmp*tmp%mod;
}

int main(void)
{
    int m; scanf("%d", &m);
    long ans=0;
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        ans=(ans+(b*powmod(a, mod-2)%mod))%mod;
    }
    printf("%ld", ans);
}

/*
    
*/