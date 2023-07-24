// https://www.acmicpc.net/problem/27966
// 2023-07-25 05:04:17
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    printf("%ld\n", n-1 + 1L*(n-2)*(n-1));
    for(int i=2; i<=n; i++)
        printf("%d %d\n", 1, i);
}

/*
    
*/