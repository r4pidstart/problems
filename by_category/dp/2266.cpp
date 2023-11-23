// https://www.acmicpc.net/problem/2266
// 2023-11-21 20:17:32
#include"bits/stdc++.h"
using namespace std;

int using_bs(int n, int k)
{
    int cnt=0, low=0;
    while(k!=1 and n-low!=1)
    {
        int current=n-low;
        low+=current/2+(current&1);
        k--;
        cnt++;
    }
    return cnt+(n-low);
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    vector<vector<int> > dp(n+1, vector<int>(k+1));

    for(int i=1; i<=n; i++)
        for(int j=1; j<=k; j++)
        {
            dp[i][j]=using_bs(i, j);
            for(int k=1; k<i and j!=1; k++)
                dp[i][j]=min(dp[i][j], max(dp[i-k][j], dp[k-1][j-1])+1);
        }

    printf("%d", dp[n][k]);
}

/*
    
*/