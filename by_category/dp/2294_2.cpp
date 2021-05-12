// https://www.acmicpc.net/problem/2294
// 2021-05-10 20:53:54 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);
    vector<int> dp(k+1, 99999); // dp[현재 가치]=사용한 갯수
    vector<int> coins(1,0);
    for(int i=1; i<n+1; i++)
    {
        int tmp; scanf("%d", &tmp);
        coins.push_back(tmp);
    }

    sort(coins.begin(), coins.end());
    dp[0]=0;

    for(int i=1; i<=n; i++) // 사용할 동전
    {
        if(k<coins[i]) break;
        for(int j=coins[i]; j<=k; j++)
            dp[j]=min(dp[j], dp[j-coins[i]]+1);
    }
    printf("%d", dp[k]==99999 ? -1 : dp[k]);
}