// https://www.acmicpc.net/problem/2485
// 2021-12-17 00:23:58 20ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    // gcd -> 가로수 최대 간격
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    int dist=arr[1]-arr[0];
    for(int i=1; i<n-1; i++) dist=gcd(dist, arr[i+1]-arr[i]);
    printf("%d", (arr.back()-arr.front()) / dist - n + 1);        
}

/*
    
*/