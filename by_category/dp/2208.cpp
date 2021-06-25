// https://www.acmicpc.net/problem/2208
// 2021-06-25 22:05:39 16ms
#include<bits/stdc++.h>
using namespace std;

vector<int> j, sum;
int dp(int end, int k)
{
    vector<int> dp(end+1, INT32_MIN/2);
    int ans=0;
    // dp[i]=max(dp[i-1]+j[i], sum(i-k+1, i)==sum[i])
    for(int i=k; i<=end; i++)
    {
        dp[i]=max(dp[i-1]+j[i], sum[i]);
        ans=max(ans, dp[i]);
    }
    return ans;
}

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);
    j.assign(n+1, 0), sum.assign(n+1, 0);
    int tmpsum=0;
    for(int i=1; i<=n; i++)
    {
        if(i>k) tmpsum-=j[i-k];
        scanf("%d", &j[i]);
        tmpsum+=j[i];
        sum[i]=tmpsum;
    }
    printf("%d", dp(n, k));
}