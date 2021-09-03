// https://www.acmicpc.net/problem/
// 
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