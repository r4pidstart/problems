// https://www.acmicpc.net/problem/25305
// 2022-08-13 23:43:16
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end(), greater<>());
    printf("%d", arr[k-1]);
}

/*
    
*/