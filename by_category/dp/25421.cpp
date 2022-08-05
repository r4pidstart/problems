// https://www.acmicpc.net/problem/25421
// 2022-08-06 05:26:36 24ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > dp(n+1, vector<int>(10));
    fill(dp[1].begin()+1, dp[1].end(), 1);
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<10; j++)
            for(int k=max(j-2, 0); k<min(10, j+3); k++)
                dp[i][j]=(dp[i][j]+dp[i-1][k])%987654321;
    }
    printf("%d", accumulate(dp[n].begin(), dp[n].end(), 0L)%987654321);
}

/*
    
*/