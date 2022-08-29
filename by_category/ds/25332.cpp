// https://www.acmicpc.net/problem/25332
// 2022-08-30 00:24:43 108ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr1(n), arr2(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr1[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &arr2[i]);
    
    long ans=0;
    map<int, int> m;
    vector<int> psum(n+1);
    m[0]=1;
    for(int i=1; i<=n; i++)
    {
        psum[i]=psum[i-1]+arr1[i-1]-arr2[i-1];
        ans+=m[psum[i]];
        m[psum[i]]++;
    }

    printf("%ld", ans);
}

/*
    
*/