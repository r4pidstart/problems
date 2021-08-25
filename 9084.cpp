// https://www.acmicpc.net/problem/9084
// 2021-08-26 06:24:51 16ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<int> coins(n+1,0);
        for(int i=0; i<n; i++)
            scanf("%d", &coins[i+1]);

        int m; scanf("%d", &m);
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        // dp[i][j] : i를 0~j까지의 동전으로 만드는 방법의 가짓수

        for(int i=0; i<=n; i++)
            dp[0][i]=1;
        for(int i=1; i<=n; i++) // i번 동전으로
            for(int j=1; j<m+1; j++) // j원을
            {
                int cnt=0;
                while(coins[i]*cnt <= j)
                {
                    dp[j][i]+=dp[j-coins[i]*cnt][i-1];
                    cnt++;
                }
            }

        printf("%d\n", dp[m][n]);
    }
}

/*
    30원
    10*3
    10*2 + (10) -> 10보다 작은 수 만으로 만든.
    10*1 + (20)
    5*6
    5*5 + (5) -> 5보다 작은 수 만으로 만든.
    5*4 + (10)
    5*3 + (15)
    5*2 + (20)
    1*30
*/