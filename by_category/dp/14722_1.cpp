// https://www.acmicpc.net/problem/14722
// 2021-05-02 15:12:57 216ms

#include<bits/stdc++.h>
using namespace std;

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
        {
            for(int k=0; k<3; k++)
            {
                if(i+1<=n) 
                    if(dp[i][j][k]!=0 && arr[i+1][j]==(k+1)%3)
                        dp[i+1][j][(k+1)%3]=max(dp[i][j][k]+1, dp[i+1][j][(k+1)%3]);
                    else
                        dp[i+1][j][k]=max(dp[i][j][k], dp[i+1][j][k]);

                if(j+1<=n) 
                    if(dp[i][j][k]!=0 && arr[i][j+1]==(k+1)%3)
                        dp[i][j+1][(k+1)%3]=max(dp[i][j][k]+1, dp[i][j+1][(k+1)%3]);
                    else
                        dp[i][j+1][k]=max(dp[i][j][k], dp[i][j+1][k]);
            }
        }

    printf("%d", max({dp[n][n][0], dp[n][n][1], dp[n][n][2]}));
}
