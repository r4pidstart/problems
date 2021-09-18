// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,a,b; scanf("%d%d%d", &n,&a,&b);
    vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(a+1, vector<int>(b+1,0)));
    dp[1][1][1]=1;
    for(int i=2; i<=n; i++)
        for(int j=1; j<=a; j++)
            for(int k=1; k<=b; k++)
                dp[i][j][k]=(dp[i-1][j-1][k]+dp[i-1][j][k-1]+(long long)dp[i-1][j][k]*(i-2))%1'000'000'007;
    printf("%d", dp[n][a][b]);
}

/*

*/