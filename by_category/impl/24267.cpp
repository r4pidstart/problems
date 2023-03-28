// https://www.acmicpc.net/problem/24267
// 2023-03-29 02:50:21
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);

    long ans=0;
    for(int i=1; i<=n-2; i++)
        ans+=i*(n-2-i+1L);
    printf("%ld\n%d", ans, 3);
}

/*
    
*/