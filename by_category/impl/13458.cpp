// https://www.acmicpc.net/problem/13458
// 2022-03-16 00:07:33 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int b,c; scanf("%d%d", &b, &c);

    long long ans=0;
    for(int i=0; i<n; i++)
    {
        ans++;
        arr[i]-=b;
        if(arr[i]>0) ans+=arr[i]/c, arr[i]-=arr[i]/c*c;
        if(arr[i]>0) ans++;
    }
    printf("%lld", ans);
}

/*
    
*/