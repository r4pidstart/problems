// https://www.acmicpc.net/problem/2294
// 2021-05-10 20:48:12 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);
    vector<vector<int> > dp(101, vector<int>(10001,100000));
    // dp[동전가짓수][현재가치]=사용한 갯수
    vector<int> coins(1,0);
    for(int i=1; i<n+1; i++)
    {
        int tmp; scanf("%d", &tmp);
        coins.push_back(tmp);
    }

    sort(coins.begin(), coins.end());
    int ans=INT32_MAX;
    for(int i=1; i<=n; i++) // 사용할 동전
    {
        if(k<coins[i]) break;
        for(int j=1; j<coins[i]; j++)
            dp[i][j]=dp[i-1][j];
        dp[i][coins[i]]=1;
        for(int j=coins[i]+1; j<=k; j++) // 만들 가치
        {
            dp[i][j]=min({dp[i-1][j], dp[i-1][j-coins[i]]+1, dp[i][j-coins[i]]+1});
        }
        ans=min(ans, dp[i][k]);
    }
    printf("%d", ans>k ? -1 : ans);
}