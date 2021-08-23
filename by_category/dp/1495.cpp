// https://www.acmicpc.net/problem/1495
// 2021-08-24 03:59:20 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,s,m; scanf("%d%d%d", &n,&s,&m);
    vector<vector<int> > dp(n+1, vector<int>(m+1,0));
    vector<int> v(n+1);
    for(int i=0; i<n; i++)
        scanf("%d", &v[i+1]);

    dp[0][s]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(dp[i-1][j])
            {
                if(j + v[i] <= m) dp[i][j+v[i]]++;
                if(j - v[i] >= 0) dp[i][j-v[i]]++;
            }
        }
    }

    for(int i=m; i>=0; i--)
        if(dp[n][i])
        {
            printf("%d", i);
            return 0;
        }
    printf("-1");
}

/*

*/