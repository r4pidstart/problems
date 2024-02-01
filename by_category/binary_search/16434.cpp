// https://www.acmicpc.net/problem/16434
// 2024-02-02 01:16:57
#include"bits/stdc++.h"
using namespace std;

int decision(long mid, long h_atk, const vector<tuple<long, long, long> >& arr)
{
    long h_curhp=mid, h_maxhp=mid;

    for(auto [t, a, h] : arr)
    {
        if(t==2)
        {
            h_atk+=a;
            h_curhp=min(h_maxhp, h_curhp+h);
        }
        else
        {
            long cnt=(h+h_atk-1)/h_atk;
            h_curhp-=a*(cnt-1);
            if(h_curhp<=0) return 0;
        }
    }
    return 1;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n, h_atk; scanf("%d%d", &n, &h_atk);
    vector<tuple<long, long, long> > arr(n);
    for(int i=0; i<n; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        arr[i]={a, b, c};
    }
    long lo=1, hi=LONG_MAX/2, ans=LONG_MAX/2;
    while(lo<=hi)
    {
        long mid=(lo+hi)/2;
        if(decision(mid, h_atk, arr))
            hi=mid-1, ans=mid;
        else
            lo=mid+1;
    }
    printf("%ld", ans);
}

/*
    
*/