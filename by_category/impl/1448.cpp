// https://www.acmicpc.net/problem/1448
// 2023-03-08 23:11:35
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n);

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i=0; i<n-2; i++)
        if(arr[i]<arr[i+1]+arr[i+2])
            return !printf("%d", arr[i]+arr[i+1]+arr[i+2]);
    printf("-1");
}

/*
    
*/