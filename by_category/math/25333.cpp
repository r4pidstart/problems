// https://www.acmicpc.net/problem/25333
// 2023-01-27 04:44:22
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", c/gcd(a,b));
    }
}

/*
    
*/