// https://www.acmicpc.net/problem/2057
// 2023-06-05 01:41:40
#include"bits/stdc++.h"
using namespace std;

int sol(unsigned long sum, long idx, long n, vector<unsigned long>& arr)
{
    if(idx==21) return 0;
    if(sum==n) return 1;

    return max(sol(sum+arr[idx], idx+1, n, arr), sol(sum, idx+1, n, arr));
}

int main(void)
{
#ifdef LOCAL
#endif
    long n; scanf("%ld", &n);

    // 20! > 1e18
    // 2^21 -> 2*1e6

    if(n==0) return !printf("NO"); // <-- adfadsfdfs
    
    vector<unsigned long> arr(21, 1);
    for(int i=1; i<=20; i++)
        arr[i]=arr[i-1]*i;

    printf((sol(0, 0, n, arr) ? "YES":"NO"));
}

/*
*/