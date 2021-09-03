// https://www.acmicpc.net/problem/15486
// 2021-09-03 22:30:32 256ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vector<int> T(n+1, 0), P(n+1, 0), dp(n+1, 0);
    for(int i=1; i<=n; i++)
        cin >> T[i] >> P[i];

    for(int i=1; i<=n; i++)
    {
        if(T[i]+i-1 <= n) dp[T[i]+i-1]=max(dp[T[i]+i-1], dp[i-1]+P[i]);
        dp[i]=max(dp[i], dp[i-1]);
    }
    printf("%d", dp[n]);
}

/*

*/