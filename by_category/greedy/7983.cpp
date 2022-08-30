// https://www.acmicpc.net/problem/7983
// 2022-08-31 03:32:48
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].second, &arr[i].first);
    sort(arr.begin(), arr.end());

    int end=1e9;
    for(int i=n-1; i>=0; i--)
        if(end < arr[i].first) end-=arr[i].second;
        else end=arr[i].first-arr[i].second;
    printf("%d", end);
}

/*
    
*/