// https://www.acmicpc.net/problem/31233
// 2024-04-02 22:35:36
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector arr(n, 0);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    if(n==2)
        return !printf("%d", min(arr.front(), arr.back()));
    
    int ans=0;
    for(int i=0; i<n-2; i++)
    {
        vector tmp(arr.begin()+i, arr.begin()+i+3);
        sort(tmp.begin(), tmp.end());
        ans=max(ans, tmp[1]);
    }
    printf("%d", ans);
}

/*
    
*/