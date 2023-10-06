// https://www.acmicpc.net/problem/20159
// 2023-10-07 01:18:42
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
    
    vector<int> psum_odd(n+1), psum_even(n+1);
    for(int i=0; i<n; i++)
    {
        psum_odd[i+1]=psum_odd[i];
        psum_even[i+1]=psum_even[i];

        if(!(i&1)) psum_odd[i+1]+=arr[i];
        else psum_even[i+1]+=arr[i];
    }

    int ans=psum_odd[n];
    for(int i=0; i<=n; i++)
        if(i&1) ans=max(ans, psum_odd[i]+psum_even[n-1]-psum_even[i]);
        else ans=max(ans, psum_odd[i]+psum_even[n]-psum_even[i]);
    printf("%d", ans);
}

/*
    
*/