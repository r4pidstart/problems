// https://www.acmicpc.net/problem/4811
// 2021-08-31 06:48:26 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<long long> > dp(31, vector<long long>(31,0));
    // dp[i][j] : 한 조각을 i번, 반 조각을 j번 꺼내서 만들어진 문자열 가짓수
    for(int i=1; i<31; i++)
        for(int j=0; j<i+1; j++)
        {
            if(i==1 || j==0) dp[i][j]=1;
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }

    while(n!=0)
    {
        printf("%lld\n", dp[n][n]);
        scanf("%d", &n);
    }
}

/*

*/