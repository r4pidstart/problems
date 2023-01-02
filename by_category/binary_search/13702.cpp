// https://www.acmicpc.net/problem/13702
// 2023-01-02 23:34:18
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    long lo=0, hi=3e9, ans=0;
    while(lo<=hi)
    {
        long mid=lo+hi>>1;
        long tmp=0;
        for(int i=0; i<n; i++)
            tmp+=arr[i]/mid;
        if(tmp < k)
            hi=mid-1;
        else
            lo=mid+1, ans=mid;
    }
    printf("%ld", ans);
}

/*
    
*/