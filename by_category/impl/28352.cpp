// https://www.acmicpc.net/problem/28352
// 2023-07-30 00:25:20
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    long ans=6;
    for(int i=11; i<=n; i++)
        ans*=i;
    printf("%ld", ans);
}

/*
    
*/