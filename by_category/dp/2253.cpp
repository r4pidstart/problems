// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n, m; scanf("%d%d", &n, &m);
    vector<int> small(n+1);
    for(int i=0; i<m; i++)
    {
        int a; scanf("%d", &a);
        small[a]=1;
    }

    vector<vector<int> > dp(n+1, vector<int>(500, INT32_MAX/2));
    dp[1][0]=0;
    for(int i=2; i<=n; i++)
        for(int j=0; j<500; j++)
        {
            if(small[i]) continue;
            if(i-(j-1) >= 0 and j)
                dp[i][j-1]=min(dp[i-(j-1)][j]+1, dp[i][j-1]);
            if(i-(j) >= 0)
                dp[i][j]=min(dp[i-(j)][j]+1, dp[i][j]);
            if(i-(j+1) >= 0)
                dp[i][j+1]=min(dp[i-(j+1)][j]+1, dp[i][j+1]);
        }
    int ans=*min_element(dp[n].begin(), dp[n].end());
    printf("%d", ans != INT32_MAX/2 ? ans:-1);
}

/*
    
*/