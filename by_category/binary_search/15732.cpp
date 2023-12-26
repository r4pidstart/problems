// https://www.acmicpc.net/problem/15732
// 2023-12-26 01:18:37
#include"bits/stdc++.h"
using namespace std;

int decision(int mid, vector<tuple<int, int, int> >& arr, int d)
{
    long cnt=0;
    // printf("%d / ", mid);
    for(auto& [a, b, c] : arr)
    {
        if(mid<a) continue;
        int s=a, e=min(mid, b);
        cnt+=(e-s+c)/c;
        // printf("%d ", cnt);
    }   
    // printf("\n");
    return cnt>=d; 
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,k,d; scanf("%d%d%d", &n, &k, &d);
    vector<tuple<int, int, int> > arr(k);
    for(int i=0; i<k; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        arr[i]={a, b, c};
    }
    int lo=1, hi=n, ans=0;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(mid, arr, d))
            hi=mid-1, ans=mid;
        else
            lo=mid+1;
    }
    printf("%d", ans);
}

/*
    
*/