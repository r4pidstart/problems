// https://www.acmicpc.net/problem/12976
// 2024-01-07 00:15:52
#include"bits/stdc++.h"
using namespace std;

const long x=123456789L;
int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    printf("3\n%ld %ld %ld %ld\n", x, 1, 1, n+x);
    #ifdef LOCAL
        printf("%ld", abs((x*1*1 + x*1*(n+x)) - (1*1*(n+x) + x*1*(n+x))));
    #endif
}

/*
    ixj jxk kxa 

    i*j*k + i*k*a, j*k*a + i*j*a
    x*1*1 + x*1*a, 1*1*a + x*1*a
    x+xa, a+xa
    2+2a, a+2a
*/