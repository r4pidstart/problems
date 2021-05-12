// https://www.acmicpc.net/problem/14722
// 2021-05-02 15:27:49 196ms
#include<bits/stdc++.h>
using namespace std;

void fill_dp(vector<vector<vector<int> > > &dp, int i, int j, int k)
{
    if(dp[i-1][j][(k+2)%3]!=0)
        dp[i][j][k]=max(dp[i-1][j][(k+2)%3]+1, dp[i][j][k]);
    if(dp[i][j-1][(k+2)%3]!=0)
        dp[i][j][k]=max(dp[i][j-1][(k+2)%3]+1, dp[i][j][k]);
    dp[i][j][(k+1)%3]=max({dp[i-1][j][(k+1)%3], dp[i][j-1][(k+1)%3], dp[i][j][(k+1)%3]});
    dp[i][j][(k+2)%3]=max({dp[i-1][j][(k+2)%3], dp[i][j-1][(k+2)%3], dp[i][j][(k+2)%3]});
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > arr(n+1, vector<int>(n+1));
    vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(n+1, vector<int>(3, 0)));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            scanf("%d", &arr[i][j]);
            if(arr[i][j]==0)
                dp[i][j][0]++;
        }
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            fill_dp(dp,i,j,arr[i][j]);

    printf("%d", max({dp[n][n][0], dp[n][n][1], dp[n][n][2]}));
}
