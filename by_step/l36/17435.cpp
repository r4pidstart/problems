// https://www.acmicpc.net/problem/17435
// 2021-06-06 17:10:28 620ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int m; scanf("%d", &m);
    int max=log2(500000)+1;
    vector<vector<int> > dp(m+1, vector<int>(max+1));
    for(int i=1; i<=m; i++)
        scanf("%d", &dp[i][0]);
    
    for(int i=1; i<=max; i++)
        for(int j=1; j<=m; j++)
            dp[j][i]=dp[dp[j][i-1]][i-1];

    int q; scanf("%d", &q);
    while(q--)
    {
        int n,m; scanf("%d%d", &n,&m);
        for(int i=0; n>0; i++)
        {
            if(n&1)
                m=dp[m][i];
            n>>=1;
        }
        printf("%d\n", m);
    }
}