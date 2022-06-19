// https://www.acmicpc.net/problem/11441
// 2022-06-20 00:33:10 60ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n+1), p_sum(n+1);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i+1]);
    for(int i=1; i<=n; i++)
        p_sum[i]=p_sum[i-1]+arr[i];
    
    int m; scanf("%d", &m);
    while(m--)
    {
        int a,b; scanf("%d%d", &a, &b);
        printf("%d\n", p_sum[b]-p_sum[a-1]);
    }
}

/*
    
*/