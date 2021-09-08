// https://www.acmicpc.net/problem/9658
// 2021-09-09 03:32:43 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> dp(n+1, 0);
    if(n>=2) dp[2]=1;
    if(n>=4) dp[4]=1;
    if(n>=5) dp[5]=1;

    for(int i=6; i<=n; i++)
        if(dp[i-1] && dp[i-3] && dp[i-4]) dp[i]=0;
        else dp[i]=1;
    
    printf("%s", dp[n] ? "SK":"CY");
}

/*

*/