// https://www.acmicpc.net/problem/1838
// 2024-02-12 04:29:23
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    vector<int> sorted(arr);
    sort(sorted.begin(), sorted.end());
    map<int, int> ma;
    for(int i=0; i<n; i++)
        ma[sorted[i]]=i;
    
    int ans=0;
    for(int i=0; i<n; i++)
        ans=max(ans, i-ma[arr[i]]);
    printf("%d", ans);
}

/*
    
*/