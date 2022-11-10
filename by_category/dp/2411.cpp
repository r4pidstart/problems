// https://www.acmicpc.net/problem/2411
// 2022-11-11 00:15:57
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m,a,b; scanf("%d%d%d%d", &n, &m, &a, &b);
    vector<vector<int> > table(n+1, vector<int>(m+1));
    int cnt=0;
    for(int i=0; i<a; i++)
    {
        int x,y; scanf("%d%d", &x, &y);
        table[x][y]=1; // item
        cnt++;
    }
    for(int i=0; i<b; i++)
    {
        int x,y; scanf("%d%d", &x, &y);
        table[x][y]=2; // obstacle
    }

    vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(m+1, vector<int>(cnt+1)));
    dp[1][0][0]=1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            for(int k=0; k<=cnt; k++)
                if(table[i][j] != 2)
                {
                    if(table[i][j] == 1 and k)
                        dp[i][j][k]=dp[i-1][j][k-1]+dp[i][j-1][k-1];
                    else
                        dp[i][j][k]=dp[i-1][j][k]+dp[i][j-1][k];
                } 
    printf("%d", dp[n][m][cnt]);
}

/*
    
*/