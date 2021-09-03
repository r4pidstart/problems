// https://www.acmicpc.net/problem/10835
// 2021-09-04 00:54:52 36ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> left(n),right(n);
    for(int i=0; i<n; i++)
        scanf("%d", &left[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &right[i]);

    int ans=0;
    vector<vector<int> > dp(n+1, vector<int>(n+1,-1));
    // dp[i][j] -> 왼쪽 i개, 오른쪽 j개 버린 상황
    dp[0][0]=0;
    for(int i=0; i<=n; i++) // left
        for(int j=0; j<=n; j++) // right
        {
            // left only
            if(i!=0 && dp[i-1][j]>=0) dp[i][j]=max(dp[i][j], dp[i-1][j]);
            // right only
            if(j!=0 && i!=n && left[i]>right[j-1] && dp[i][j-1]>=0) dp[i][j]=max(dp[i][j], dp[i][j-1]+right[j-1]);
            // both
            if(j!=0 && i!=0 && dp[i-1][j-1]>=0) dp[i][j]=max(dp[i][j], dp[i-1][j-1]);
            ans=max(ans, dp[i][j]);
        }

    printf("%d", ans);
}

/*

*/