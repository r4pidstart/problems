// https://www.acmicpc.net/problem/23320
// 2021-11-01 23:49:28 A
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    int x,y; scanf("%d%d", &x, &y);
    printf("%d %d", n*x/100 ,arr.end()-lower_bound(arr.begin(), arr.end(), y));
}

/*
    
*/