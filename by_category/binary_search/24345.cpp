// https://www.acmicpc.net/problem/23345
// 2022-05-01 23:40:45 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<int> arr(k);
    for(int i=0; i<k; i++)
        scanf("%d", &arr[i]);
    
    long long lo=0, hi=LLONG_MAX/2, ans=LLONG_MAX/2;
    while(lo <= hi)
    {
        __int128_t mid=(lo+hi)/2, tmp=0;
        for(int computer : arr)
            tmp+=mid/computer;
        
        if(tmp >= n)
            ans=mid, hi=mid-1;
        else
            lo=mid+1;
    }
    printf("%lld", ans);
}

/*
    
*/