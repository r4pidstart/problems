// https://www.acmicpc.net/problem/22981
// 2024-07-05 11:49:28
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int decision(long mid, long k, long t1, long t2, long h1, long h2)
{
    // mid*t1*h1 + mid*t2*h2 >= k
    // (t1*h1 + t2*h2)*mid>=k
    // mid>=k/(t1*h1 + t2*h2)
    return ((__int128_t)mid*t1*h1 + (__int128_t)mid*t2*h2) >= k;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    long n,k; cin >> n >> k;
    vector<long> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    long ans=LONG_MAX;
    sort(arr.begin(), arr.end());
    for(int i=1; i<n; i++)
    {
        int t1=arr[0], t2=arr[i];
        int h1=i, h2=n-i;
        
        long lo=0, hi=k, tmp=k;
        while(lo<=hi)
        {
            long mid=(lo+hi)/2;
            if(decision(mid, k, t1, t2, h1, h2))
                hi=mid-1, tmp=mid;
            else
                lo=mid+1;
        }
        ans=min(ans, tmp);
    }
    cout << ans;
}

/*
    
*/
