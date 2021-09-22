// https://www.acmicpc.net/problem/2410
// 2021-09-23 01:25:18 772ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> binary(1,0);
    vector<vector<int> > dp(n+1, vector<int>(21, 0));
    // dp[i][j] = i를 j번째 2의 멱수까지 사용해서 만든 경우의 수
    for(int i=1; i<=10000000; i*=2)
        binary.push_back(i);

    dp[0][1]=1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=20 && binary[j]<=i; j++)
            for(int k=1; k<=j; k++)
                    dp[i][j]=(dp[i][j]+dp[i-binary[j]][k])%(int)1e9;
                
    printf("%lld", (accumulate(dp[n].begin(), dp[n].end(), 0LL))%(int)1e9);
}

/*

*/