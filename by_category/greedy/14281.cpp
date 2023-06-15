// https://www.acmicpc.net/problem/14281
// 2023-06-15 20:12:29
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<long> arr(n);
    for(int i=0; i<n; i++)
        scanf("%ld", &arr[i]);

    long ans=0;
    int flag;
    while(true)
    {
        flag=0;
        for(int i=1; i<n-1; i++)
        {
            long tmp=max(0L, arr[i]-(arr[i-1]+arr[i+1])/2);
            ans+=tmp, arr[i]-=tmp;
            if(tmp) flag=1;
        }
        for(int i=n-2; i>0; i--)
        {
            long tmp=max(0L, arr[i]-(arr[i-1]+arr[i+1])/2);
            ans+=tmp, arr[i]-=tmp;
            if(tmp) flag=1;
        }
        if(!flag) break;
    }
    printf("%ld", ans);
}

/*
    
*/