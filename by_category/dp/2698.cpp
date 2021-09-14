// https://www.acmicpc.net/problem/2698
// 2021-09-15 00:24:40 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    vector<vector<vector<int> > > dp(101, vector<vector<int> >(101, vector<int>(2,0)));
    // dp[i][j][k] : 길이 i, 인접비트 j개, k로 끝나는 수열의 개수
    dp[1][0][0]=1, dp[1][0][1]=1;
    for(int i=2; i<101; i++)
        for(int j=0; j<101; j++)
        {
            // 0을 붙이는 경우
            dp[i][j][0]+=dp[i-1][j][0]+dp[i-1][j][1];
            // 단순히 1을 붙이는 경우
            dp[i][j][1]+=dp[i-1][j][0];
            // 인접비트 수를 늘리는 경우
            if(j)
                dp[i][j][1]+=dp[i-1][j-1][1];
        }
    while(t--)
    {
        int a,b; scanf("%d%d", &a,&b);
        printf("%d\n", dp[a][b][0]+dp[a][b][1]);
    }
}

/*
0
1
*/