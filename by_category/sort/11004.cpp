// https://www.acmicpc.net/problem/11004
// 2022-03-17 15:22:36 1508ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    sort(arr.begin(), arr.end());

    printf("%d", arr[k-1]);
}

/*
    
*/