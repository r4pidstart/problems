// https://www.acmicpc.net/problem/30007    
// 2023-11-04 00:41:00  
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    while(n--)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", a*(c-1)+b);
    }
}

/*
    
*/