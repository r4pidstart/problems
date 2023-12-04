// https://www.acmicpc.net/problem/24553    
// 2023-12-03 15:16:05
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        long n; scanf("%ld", &n);
        printf("%d\n", n%10==0);
    }
}

/*
    
*/