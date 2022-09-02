// https://www.acmicpc.net/problem/2015
// 2022-09-03 02:36:04 44ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    map<int, int> m;
    m[0]=1;
    long ans=0;
    vector<int> psum(n+1);
    for(int i=1; i<=n; i++)
    {
        psum[i]=psum[i-1]+arr[i-1];
        ans+=m[psum[i]-k];
        m[psum[i]]++;
    }
    printf("%ld", ans);
}   

/*
    
*/