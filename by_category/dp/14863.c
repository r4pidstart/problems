#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdint.h>

int max(int a, int b)
{
    if(a<b) return b;
    else return a;
}

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);

    int by_walk[n+1], by_bycle[n+1], walk_money[n+1], bycle_money[n+1];
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d%d%d", &by_walk[i], &walk_money[i], &by_bycle[i], &bycle_money[i]);
        // assert(by_walk[i]&&walk_money[i]&&by_bycle[i]&&bycle_money[i]);
    }
    
    int dp[n+1][k+1];
    for(int i=0; i<=n; i++)
        for(int j=0; j<=k; j++)
            dp[i][j]=INT32_MIN/2;

    dp[0][0]=0;
    for(int i=1; i<=n; i++)
        for(int j=0; j<=k; j++)
        {
            // dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            if(j-by_walk[i] >= 0)
                dp[i][j]=max(dp[i][j], dp[i-1][j-by_walk[i]]+walk_money[i]);
            if(j-by_bycle[i] >= 0)
                dp[i][j]=max(dp[i][j], dp[i-1][j-by_bycle[i]]+bycle_money[i]);
            #ifdef LOCAL
                printf("\n");
                for(int i=0; i<n+1; i++)
                {
                    for(int j=0; j<k+1; j++)
                        printf("%12d ", dp[i][j]);
                    printf("\n");
                }
            #endif
        }
    // printf("%d", dp[n][k]);
    int ans=0;
    for(int i=0; i<=k; i++)
        ans=max(ans, dp[n][i]);
    printf("%d", ans);
}
