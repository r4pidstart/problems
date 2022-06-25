// https://www.acmicpc.net/problem/25306
// 2022-06-25 21:04:08 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    long long a,b; scanf("%lld%lld", &a, &b);

    long long ans=0;
    if(a&1)
        ans^=a++;
    if(b&1)
        ans^=!((b-a)/2&1);
    else
        ans^=b+((b-a)/2&1);
    
    printf("%lld\n", ans);
}

/*
    
*/