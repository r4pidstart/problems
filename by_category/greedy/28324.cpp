// https://www.acmicpc.net/problem/28324
// 2024-01-21 09:21:28
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
    
    reverse(arr.begin(), arr.end());
    long sum=0, now=1;
    for(int i : arr)
    {
        now=min(now, 1L*i);
        sum+=now;
        now++;
    }
    printf("%ld", sum);
}

/*
    
*/