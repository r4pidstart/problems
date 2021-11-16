// https://www.acmicpc.net/problem/2212
// 2021-11-17 03:13:16 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<int> arr(n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());

    vector<int> dist(n-1);
    for(int i=0; i<n-1; i++) dist[i]=arr[i+1]-arr[i];
    sort(dist.begin(), dist.end());

    int ans=0;
    for(int i=0; i<n-1 - k+1; i++) ans+=dist[i];
    printf("%d", ans);
}

/*
    
*/