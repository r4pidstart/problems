// https://www.acmicpc.net/problem/2302
// 2021-08-26 20:55:17 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<int> vip(n+1,0);
    for(int i=0; i<m; i++)
    {
        int a; scanf("%d", &a);
        vip[a]++;
    }

    vector<vector<int> > dp(n+1, vector<int>(2,0));
    dp[1][0]=1;
    for(int i=2; i<n+1; i++)
    {
        if(vip[i])
            dp[i][0]=dp[i-1][0]+dp[i-1][1];
        else if(vip[i-1])
            dp[i][0]=dp[i-1][0];
        else
        {
            dp[i][0]=dp[i-1][0]+dp[i-1][1];
            dp[i][1]=dp[i-1][0];
        }
    }
    printf("%d", dp[n][0]+dp[n][1]);
}

/*

*/