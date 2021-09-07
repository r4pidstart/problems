// https://www.acmicpc.net/problem/2616
// 2021-09-07 22:39:45 8ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n), prefix_sum(n+1);
    vector<vector<int> > dp(n+1, vector<int>(3,0));
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int k; scanf("%d", &k);

    prefix_sum[0]=0;
    for(int i=1; i<=n; i++)
        prefix_sum[i]=prefix_sum[i-1]+arr[i-1];

    for(int i=k; i<=n; i++)
        dp[i][0]=max(dp[i-1][0], prefix_sum[i]-prefix_sum[i-k]); // 1차

    for(int i=k*2; i<=n; i++)
        dp[i][1]=max(dp[i-1][1], dp[i-k][0]+prefix_sum[i]-prefix_sum[i-k]); // 2차

    for(int i=k*3; i<=n; i++)
        dp[i][2]=max(dp[i-1][2], dp[i-k][1]+prefix_sum[i]-prefix_sum[i-k]); // 3차

    printf("%d", dp[n][2]);
}

/*

*/