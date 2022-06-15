// https://www.acmicpc.net/problem/1940
// 2022-06-16 01:09:58 4ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());

    int ans=0, l=0, r=n-1;
    while(l<r)
    {
        if(arr[l]+arr[r] == m) ans++, l++, r--;
        else if(arr[l]+arr[r] > m) r--;
        else l++;
    }
    printf("%d", ans);
}

/*
    
*/