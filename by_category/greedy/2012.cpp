// https://www.acmicpc.net/problem/2012
// 2021-12-01 00:01:06 116ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    long long ans=0;
    for(int i=0; i<n; i++)
        ans+=abs(i+1-arr[i]);
    printf("%lld", ans);
}
