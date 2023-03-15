// https://www.acmicpc.net/problem/1407
// 2023-03-16 01:03:07
#include"bits/stdc++.h"
using namespace std;

long ans(long n)
{
    if(n==0) return 0;
    return n/2+(n&1)+ans(n/2)*2;
}

int main(void)
{
#ifdef LOCAL
#endif
    long a,b; scanf("%ld%ld", &a, &b);
    printf("%ld", ans(b)-ans(a-1));
}

/*

*/