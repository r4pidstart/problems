// https://www.acmicpc.net/problem/5527
// 2023-10-29 03:33:38
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n+1);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i+1]);
    
    int ans=0;
    vector<vector<int> > dp(n+1, vector<int>(2));
    for(int i=1; i<=n; i++)
        {
            if(arr[i]==(i&1))
                dp[i][0]=dp[i-1][0]+1, dp[i][1]=0;
            else
                dp[i][1]=dp[i-1][1]+1, dp[i][0]=0;
            ans=max({ans, dp[i][0], dp[i][1]});
        }

    for(int i=n; i>=1; i--)
        for(int j=0; j<2; j++)
        {
            int first_section=dp[i][j];
            int second_section=dp[i-first_section][j^1];
            int third_section=dp[i-first_section-second_section][j];
            ans=max(ans, first_section+second_section+third_section);
        }
    printf("%d", ans);
}

/*
    
*/