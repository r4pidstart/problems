// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

int check(long long m, int n)
{
    double cnt=0;
    for(int i : arr)
        cnt+=(long long)(m/i);
    
    return n>cnt ? 0:1; 
}

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    arr.assign(n,0);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    long long lo=1, hi=1e9*1e9, ans=1e9*1e9;
    while(lo<=hi)
    {
        long long mid=(lo+hi)/2;
        if(check(mid, m))
        {
            ans=mid;
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
    printf("%lld", ans);
}

/*
    
*/