// https://www.acmicpc.net/problem/15673
// 2021-11-15 02:05:14 20ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<long long> rdpMax(n+1), rdpMin(n+1), dpMax(n+1), dpMin(n+1), 
                        arr(n+1), minCache(n+1), maxCache(n+1);
    for(int i=0; i<n; i++) scanf("%lld", &arr[i+1]);

    dpMax[1]=dpMin[1]=maxCache[1]=minCache[1]=arr[1];
    for(int i=2; i<=n; i++)
    {
        if(maxCache[i-1]<0) maxCache[i]=arr[i]; else maxCache[i]=maxCache[i-1]+arr[i];
        if(minCache[i-1]>0) minCache[i]=arr[i]; else minCache[i]=minCache[i-1]+arr[i];
        dpMax[i]=max(dpMax[i-1], maxCache[i]);
        dpMin[i]=min(dpMin[i-1], minCache[i]);
    }

    minCache=maxCache=vector<long long>(n+1);
    rdpMax[n]=rdpMin[n]=minCache[n]=maxCache[n]=arr[n];
    for(int i=n-1; i>=0; i--)
    {
        if(maxCache[i+1]<0) maxCache[i]=arr[i]; else maxCache[i]=maxCache[i+1]+arr[i];
        if(minCache[i+1]>0) minCache[i]=arr[i]; else minCache[i]=minCache[i+1]+arr[i];
        rdpMax[i]=max(rdpMax[i+1], maxCache[i]);
        rdpMin[i]=min(rdpMin[i+1], minCache[i]);
    }

    long long ans=LLONG_MIN;
    for(int i=1; i<n; i++)
        ans=max({ans, 
                dpMax[i]*rdpMax[i+1],
                dpMin[i]*rdpMin[i+1],
                dpMax[i]*rdpMin[i+1],
                dpMin[i]*rdpMax[i+1]});
    printf("%lld", ans);
}

/*
    
*/