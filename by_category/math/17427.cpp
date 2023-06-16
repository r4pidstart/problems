// https://www.acmicpc.net/problem/17427
// 2023-06-16 23:23:50
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    long ans=0;
    for(int i=1; i<=n; i++)
        ans+=n/i*i;
    printf("%ld", ans);
}

/*
    
*/