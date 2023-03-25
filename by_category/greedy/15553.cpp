// https://www.acmicpc.net/problem/15553
// 2023-03-26 01:30:33
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());

    vector<int> duration;
    for(int i=1; i<n; i++)
        duration.push_back(arr[i]-arr[i-1]);
    sort(duration.begin(), duration.end());

    int target=max(0, n-k), ans=k;
    for(int i=0; i<target; i++)
        ans+=duration[i];

    printf("%d", ans);
}

/*
    
*/