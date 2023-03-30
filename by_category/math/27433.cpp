// https://www.acmicpc.net/problem/27433
// 2023-03-31 04:31:33
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    long ans=1; while(n--) ans*=n+1;
    printf("%ld", ans);
}

/*
    
*/