// https://www.acmicpc.net/problem/2624
// 2021-09-09 02:52:52 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t,k; scanf("%d%d", &t,&k);
    vector<pair<int,int> > coins(k+1);
    for(int i=1; i<=k; i++)
        scanf("%d%d", &coins[i].first, &coins[i].second);

    vector<vector<int> > dp(k+1, vector<int>(t+1,0));
    // dp[i][j] : i번까지의 동전을 가지고 j원을 만들 수 있는 경우의 수

    for(int i=1; i<=k; i++)
    {
        for(int j=1; j<=t; j++)
            if(coins[i].first <= j)
            {
                if(j%coins[i].first == 0 && j/coins[i].first <= coins[i].second) dp[i][j]=1;
                for(int cnt=1; cnt<=coins[i].second && coins[i].first*cnt<=j; cnt++)
                    dp[i][j]+=dp[i-1][j-coins[i].first*cnt];
            }
        for(int j=1; j<=t; j++)
            dp[i][j]+=dp[i-1][j];
    }
    printf("%d", dp[k][t]);
}

/*

*/