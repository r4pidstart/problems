// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<long long> rdpMax(n+1), rdpMin(n+1), dpMax(n+1), dpMin(n+1), 
                        arr(n+1), minCache(n+1), maxCache(n+1);
    for(int i=0; i<n; i++) scanf("%d", &arr[i+1]);

    minCache[0]=maxCache[0]=arr[1];
    for(int i=1; i<=n; i++)
    {
        if(maxCache[i-1]<0) maxCache[i]=arr[i]; else maxCache[i]=maxCache[i-1]+arr[i];
        if(mi>0) mi=arr[i]; else mi+=arr[i];
        dpMax[i]=max(dpMax[i-1], ma);
        dpMin[i]=min(dpMin[i-1], mi);
    }

    minCache[n-1]=maxCache[n-1]=arr[n];
    for(int i=n-1; i>=0; i--)
    {
        if(ma<0) ma=arr[i+1]; ma+=arr[i+1];
        if(mi>0) mi=arr[i+1]; mi+=arr[i+1];
        rdpMax[i]=max(rdpMax[i+1], ma);
        rdpMin[i]=min(rdpMin[i+1], mi);
    }

    long long ans=0;
    for(int i=1; i<n-1; i++)
        ans=max({ans, 
                dpMax[i]*rdpMax[i+1],
                dpMin[i]*rdpMin[i+1],
                dpMax[i]*rdpMin[i+1],
                dpMin[i]*rdpMax[i+1]});
    printf("%lld", ans);
}

/*
    
*/