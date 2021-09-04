// https://www.acmicpc.net/problem/2688
// 2021-09-05 03:11:31 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    vector<vector<long long> > dp(65, vector<long long>(10, 0));
    // dp[i][j] : 줄어들지 않는 i자리수 중 j로 끝나는 것.
    for(int i=0; i<10; i++)
        dp[1][i]=1;

    for(int i=2; i<65; i++)
        for(int j=0; j<10; j++)
            for(int k=0; k<=j; k++)
                dp[i][j]+=dp[i-1][k];
    
    while(t--)
    {
        int n; scanf("%d", &n);
        printf("%lld\n", accumulate(dp[n].begin(), dp[n].end(), 0ll));
    }
}

/*

*/