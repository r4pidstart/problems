// https://www.acmicpc.net/problem/1535
// 2021-09-06 23:45:20 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d",&n);
    vector<int> health(n,0), happy(n,0);
    vector<vector<int> > dp(n+1, vector<int>(100, 0));

    for(int i=0; i<n; i++)
        scanf("%d", &health[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &happy[i]);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=99; j++) // 체력을 100 사용하지 못 함
            if(j>=health[i-1]) dp[i][j]=max(dp[i-1][j], dp[i-1][j-health[i-1]]+happy[i-1]);
            else dp[i][j]=dp[i-1][j];
    
    printf("%d", dp[n][99]);
}

/*

*/