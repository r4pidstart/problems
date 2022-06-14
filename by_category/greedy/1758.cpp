// https://www.acmicpc.net/problem/1758
// 2022-06-15 00:07:03 16ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end(), greater<>());

    long long ans=0;
    for(int i=0; i<n; i++)
        ans+=max(arr[i]-i, 0);
    printf("%lld", ans);
}

/*
    
*/