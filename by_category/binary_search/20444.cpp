// https://www.acmicpc.net/problem/20444
// 2023-11-26 19:37:48
#include"bits/stdc++.h"
using namespace std;


int main(void)
{
#ifdef LOCAL
#endif
    long n,k; scanf("%ld%ld", &n, &k);

    long lo=0, hi=n/2;
    while(lo<=hi)
    {
        long mid=(lo+hi)/2;
        if((mid+1) * (n-mid+1) == k)
            return !printf("YES");
        else if((mid+1) * (n-mid+1) > k)
            hi=mid-1;
        else
            lo=mid+1;
    }
    printf("NO");
}

/*

*/