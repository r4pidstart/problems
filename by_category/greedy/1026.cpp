// https://www.acmicpc.net/problem/1026
// 2021-11-06 03:31:49 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> a(n),b(n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) scanf("%d", &b[i]);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int ans=0;
    for(int i=0; i<n; i++)
        ans+=a[i]*b[n-1-i];

    printf("%d", ans);
}

/*
    
*/