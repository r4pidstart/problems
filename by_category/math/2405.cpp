// https://www.acmicpc.net/problem/2405
// 2023-11-19 01:11:48
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<long> arr(n);
    for(int i=0; i<n; i++)
        scanf("%ld", &arr[i]), arr[i]*=3;
    sort(arr.begin(), arr.end());

    long ans=0;
    for(int i=2; i<n; i++)
        ans=max(ans, abs(arr[0]+arr[i] - 2*arr[i-1]));
    for(int i=0; i<n-2; i++)
        ans=max(ans, abs(arr[i]+arr[n-1] - 2*arr[i+1]));

    printf("%ld", ans/3);
}

/*
    
*/