// https://www.acmicpc.net/problem/13398
// 2021-08-28 02:28:40 12ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > dp(n+1, vector<int>(2,0)); 
    vector<int> nums(n+1, 0);
    for(int i=0; i<n; i++)
        scanf("%d", &nums[i+1]);
    int ans=dp[1][0]=nums[1];
    for(int i=2; i<=n; i++)
    {
        dp[i][0]=max(dp[i-1][0]+nums[i], nums[i]);
        dp[i][1]=max(dp[i-1][1]+nums[i], dp[i-2][0]+nums[i]);
        ans=max({ans, dp[i][0], dp[i][1]});
    }
    printf("%d", ans);
}

/*

*/