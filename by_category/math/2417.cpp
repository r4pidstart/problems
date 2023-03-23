// https://www.acmicpc.net/problem/2417     
// 2023-03-23 13:04:40
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    unsigned long n; scanf("%lu", &n);
    unsigned long lo=0, hi=UINT32_MAX-1, ans=UINT32_MAX-1;

    if(n==0) return !printf("0");

    while(lo<=hi)
    {
        unsigned long mid=(lo+hi)/2;
        if(mid*mid >= n)
            hi=mid-1, ans=mid;
        else
            lo=mid+1;
    }
    printf("%lu", ans);
}

/*
    
*/