// https://www.acmicpc.net/problem/5347
// 2023-02-16 00:55:03
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        long a,b; scanf("%ld%ld", &a, &b);
        printf("%ld\n", lcm(a, b));
    }
}

/*
    
*/
