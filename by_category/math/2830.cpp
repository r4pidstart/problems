// https://www.acmicpc.net/problem/2830
// 2023-11-22 22:05:21
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    long ans=0, cur=1;
    while(cur < 1000000)
    {
        long cnt[2]={};
        for(int i=0; i<n; i++)
            cnt[!!(arr[i]&cur)]++;
        ans+=cur * (cnt[0]*cnt[1]);
        cur<<=1;
    }
    printf("%ld", ans);
}  

/*
    
*/