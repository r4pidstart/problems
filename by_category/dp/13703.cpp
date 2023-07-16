// https://www.acmicpc.net/problem/13703
// 2023-07-17 02:46:37
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int k,n; scanf("%d%d", &k, &n);
    vector<vector<unsigned long> > dp(n+1, vector<unsigned long>(k+n+2));

    dp[0][k]=1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=k+n; j++)
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
    if(!k) printf("0");
    else printf("%lu", accumulate(dp[n].begin(), dp[n].end(), 0ul));
}

/*
    
*/