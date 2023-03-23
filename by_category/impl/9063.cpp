// https://www.acmicpc.net/problem/9063
// 2023-03-24 03:06:38
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    int lo_x=INT32_MAX, hi_x=INT32_MIN, lo_y=INT32_MAX, hi_y=INT32_MIN;
    while(n--)
    {
        int a,b; scanf("%d%d", &a, &b);
        lo_x=min(lo_x, a);
        hi_x=max(hi_x, a);

        lo_y=min(lo_y, b);
        hi_y=max(hi_y, b);
    }
    printf("%ld", (long)(hi_x-lo_x)*(hi_y-lo_y));
}

/*
    
*/