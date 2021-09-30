// https://www.acmicpc.net/problem/2872
// 2021-10-01 01:49:28 48ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    int ans=0, prev=n;
    for(auto it=arr.rbegin(); it<arr.rend(); it++)
    {
        if(prev==*it) prev--;
        else ans++;
    }
    printf("%d", ans);
}

/*
    
*/