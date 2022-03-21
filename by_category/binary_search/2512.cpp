// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int lim; scanf("%d", &lim);
    if(accumulate(arr.begin(), arr.end(), 0) <= lim)
        return !printf("%d", *max_element(arr.begin(), arr.end()));

    int lo=0, hi=1e9, ans=0;
    while(lo<=hi)
    {
        long long sum=0, mid=(lo+hi)/2;
        for(int i : arr)
        {
            if(i >= mid) sum+=mid;
            else sum+=i;
        }
        if(sum <= lim)
        {
            lo=mid+1;
            ans=mid;
        }
        else
        {
            hi=mid-1;
        }
    }
    printf("%d", ans);
}

/*
    
*/