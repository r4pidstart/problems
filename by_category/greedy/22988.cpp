// https://www.acmicpc.net/problem/22988
// 2024-03-20 20:31:47
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    long n,x; scanf("%ld%ld", &n, &x);
    vector<long> arr(n);
    for(int i=0; i<n; i++)
        scanf("%ld", &arr[i]);
    
    for(int i=0; i<n; i++)
        arr[i]*=2;

    x*=2;
    sort(arr.begin(), arr.end());
    
    int ans=0, remain=0, lo=0, hi=n-1;
    while(hi>=0 and arr[hi]>=x)
        ans++, hi--;

    while(lo<n and arr[lo]+arr[hi]<x/2)
        lo++, remain++;

    while(lo<=hi)
    {
        if(lo!=hi and arr[lo]+arr[hi]>=x/2)
            lo++, hi--, ans++;
        else
            remain++, lo++;
    }

    printf("%d", ans+remain/3);
}

/*
    
*/