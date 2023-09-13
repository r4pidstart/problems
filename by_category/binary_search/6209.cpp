// https://www.acmicpc.net/problem/6209
// 2023-09-14 01:47:54
#include"bits/stdc++.h"
using namespace std;

int decision(int mid, vector<int>& arr, int m)
{
    int prev=0;
    for(int i=0; i<arr.size(); i++)
        if(arr[i]-prev < mid) m--;
        else prev=arr[i];
    return m>=0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int d,n,m; scanf("%d%d%d", &d, &n, &m);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    arr.push_back(d);
    sort(arr.begin(), arr.end());

    int lo=0, hi=1e9, ans=0;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(mid, arr, m))
            lo=mid+1, ans=mid;
        else
            hi=mid-1;
    }
    printf("%d", ans);
}

/*
    
*/