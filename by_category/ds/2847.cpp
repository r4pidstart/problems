// https://www.acmicpc.net/problem/2847
// 2021-11-17 02:37:01 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,cnt=0; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=n-2; i>=0; i--)
        if(arr[i] >= arr[i+1]) 
        {
            cnt+=arr[i]-arr[i+1]+1;
            arr[i]=arr[i+1]-1;
        }
    printf("%d", cnt);
}

/*
    
*/