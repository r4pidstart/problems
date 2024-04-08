// https://www.acmicpc.net/problem/17845
// 2024-04-04 19:58:48
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<pair<int, int> > arr(k+1);
    for(int i=1; i<=k; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    vector<vector<int> > dp(n+1, vector<int>(k+1, 0));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=k; j++)
        {
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            if(i-arr[j].second >= 0)
                dp[i][j]=max(dp[i][j], dp[i-arr[j].second][j-1]+arr[j].first);
        }
    printf("%d", dp[n][k]);
}

/*
    
*/