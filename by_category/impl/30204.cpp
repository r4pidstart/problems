// https://www.acmicpc.net/problem/30204
// 2023-10-19 04:57:25
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    printf("%d", accumulate(arr.begin(), arr.end(), 0)%k==0);
}

/*
    
*/