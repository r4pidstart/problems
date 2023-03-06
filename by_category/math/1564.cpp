// https://www.acmicpc.net/problem/1564
// 2023-03-06 18:55:28
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    __int128_t a=1;
    n++;
    while(--n)
    {
        a*=n;
        while(!(a%10)) a/=10;
        a%=__int128_t(1e13);
        assert(a>0);
    }
    printf("%05ld", a%100000);
}

/*
    
*/