// https://www.acmicpc.net/problem/28648
// 2023-08-23 03:24:23
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    int ans=INT32_MAX;
    while(t--)
    {
        int a,b; scanf("%d%d", &a, &b);
        ans=min(ans, a+b);
    }
    printf("%d", ans);
}

/*
    
*/