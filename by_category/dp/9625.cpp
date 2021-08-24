// https://www.acmicpc.net/problem/9625
// 2021-08-25 01:29:38 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > dp(n+1, pair<int,int>({0,0}));
    dp[0]={1,0};
    for(int i=1; i<=n; i++)
        dp[i]={dp[i-1].second, dp[i-1].second+dp[i-1].first};
    printf("%d %d", dp[n].first, dp[n].second);
}

/*

*/