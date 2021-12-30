// https://www.acmicpc.net/problem/23978
// 2021-12-31 05:50:28 256ms
#include<bits/stdc++.h>
using namespace std;

long long decision(const vector<int>& arr, const long long& price)
{
    long long sum=0; 
    for(int i=0; i<arr.size()-1; i++)
    {
        long long duration=arr[i+1]-arr[i];
        if(duration >= price) sum+=price*(price+1)/2;
        else sum+=duration*(duration+1)/2 + duration*(price-duration);
    }
    sum+=price*(price+1)/2;
    return sum;
}

int main(void)
{
    long long n,k; scanf("%lld%lld", &n,&k);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    long long lo=1, hi=2e9, ans=hi;
    while(lo<=hi)
    {
        long long mid=(lo+hi)/2;
        if(decision(arr, mid) < k)
        {
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
            ans=mid;
        }
    }
    printf("%lld", ans);
}

/*
    
*/