// https://www.acmicpc.net/problem/23816
// 2023-02-23 21:53:47
#include"bits/stdc++.h"
using namespace std;

// int solution(int now, int n, int m)
// {
//     static vector<vector<int> > dp(m+1, vector<int>(n+1, -1));

//     if(!m) return 0;
//     if(m<0 or now==n) return INT32_MIN/2;
//     if(dp[m][now] != -1) return dp[m][now];
    
//     int ret=INT32_MIN/2;
//     ret=max(ret, solution(now+1, n, m-1)+1);
//     ret=max(ret, solution(now+1, n, m-3)+2);
//     ret=max(ret, solution(now+1, n, m-7)+4);
//     ret=max(ret, solution(now+1, n, m-15));

//     return dp[m][now]=ret;
// }

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    // int ans=solution(0, n, m);
    // printf("%d", (ans<0) ? -1:ans);

    vector<vector<int> > dp(n+1, vector<int>(m+1, INT32_MIN/2));
    dp[0][0]=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(j>=1)
                dp[i][j]=max(dp[i][j], dp[i-1][j-1]+1);
            if(j>=3)
                dp[i][j]=max(dp[i][j], dp[i-1][j-3]+2);
            if(j>=7)
                dp[i][j]=max(dp[i][j], dp[i-1][j-7]+4);
            if(j>=15)
                dp[i][j]=max(dp[i][j], dp[i-1][j-15]);
        }
    int ans=0;
    for(int i=1; i<=n; i++)
        ans=max(ans, dp[i][m]);
    printf("%d", ans ? ans:-1);
}

/*
    
*/