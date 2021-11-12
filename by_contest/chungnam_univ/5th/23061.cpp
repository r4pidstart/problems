// https://www.acmicpc.net/problem/23061
// 2021-11-13 03:45:36 G
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<int> weigh(n+1), value(n+1), backpack(m+1);
    for(int i=0; i<n; i++) scanf("%d%d", &weigh[i+1], &value[i+1]);
    for(int i=0; i<m; i++) scanf("%d", &backpack[i+1]);

    // knapsack
    vector<vector<int> > dp(n+1, vector<int>(1000001,0));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=1000000; j++)
        {
            if(weigh[i] > j) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j], dp[i-1][j-weigh[i]]+value[i]);
        }

    int ansNum=1; double ansEff=0;
    for(int i=1; i<=m; i++)
        if(dp[n][backpack[i]] and ansEff < (double)dp[n][backpack[i]] / backpack[i])
            ansNum=i, ansEff=(double)dp[n][backpack[i]] / backpack[i];
    printf("%d", ansNum);
}

/*
    
*/