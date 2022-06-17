// https://www.acmicpc.net/problem/2230
// 2022-06-18 05:06:19 28ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    long long n,m; scanf("%lld%lld", &n, &m);
    vector<long long> arr(n);
    for(int i=0; i<n; i++) 
        scanf("%lld", &arr[i]);

    long long ans=INT32_MAX;
    sort(arr.begin(), arr.end());
    int l=0, r=1;
    while(l<n and r<n)
    {
        long long dif=abs(arr[l]-arr[r]);
        if(dif < m) r++;
        else
        {
            ans=min(dif, ans);
            l++;
        }
    }
    printf("%lld", ans);
}

/*
    
*/