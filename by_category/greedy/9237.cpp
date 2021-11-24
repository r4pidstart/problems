// https://www.acmicpc.net/problem/9237
// 2021-11-24 23:02:44 20ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end(), greater<int>());

    int ans=0;
    for(int i=0; i<n; i++)
        ans=max(ans, i+arr[i]+2);
    printf("%d", ans);
}

/*
    
*/