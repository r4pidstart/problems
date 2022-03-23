// https://www.acmicpc.net/problem/2506
// 2022-03-23 23:29:02 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    for(int i=1; i<n; i++)
        if(arr[i]) arr[i]+=arr[i-1];

    printf("%d", accumulate(arr.begin(), arr.end(), 0));
}

/*
    
*/