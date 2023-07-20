// https://www.acmicpc.net/problem/1263
// 2023-07-20 16:11:13
#include"bits/stdc++.h"
using namespace std;

int check(int mid, vector<tuple<int, int> >& arr)
{
    for(auto& [e, t] : arr)
    {
        if(mid+t>e) return 0;
        else mid+=t;
    }
    return 1;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<tuple<int, int> > arr(n);
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        arr[i]={b, a};
    }
    
    sort(arr.begin(), arr.end());

    int lo=0, hi=1000000, ans=-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(check(mid, arr))
            ans=mid, lo=mid+1;
        else
            hi=mid-1;
    }
    printf("%d", ans);
}

/*
    
*/