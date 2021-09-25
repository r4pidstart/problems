// https://www.acmicpc.net/problem/21758
// 2021-09-26 01:19:18 16ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> prefix_sum(n+1,0), arr(n+1,0);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &arr[i]);
        prefix_sum[i]=prefix_sum[i-1]+arr[i];
    }

    int ans=0;
    int a=prefix_sum[n]-prefix_sum[1]; // 2~n 
    int b=prefix_sum[n-1]; // 1~n-1
    for(int i=2; i<n; i++)
    {
        ans=max(ans, a-arr[i]+prefix_sum[n]-prefix_sum[i]); // 1,i | n
        ans=max(ans, b-arr[i]+prefix_sum[i-1]); // n,i | 1
        ans=max(ans, prefix_sum[i]-prefix_sum[1]+prefix_sum[n-1]-prefix_sum[i-1]); // 1,n | i
    }
    
    printf("%d",ans);
}

/*
    
*/