// https://www.acmicpc.net/problem/11985
// 2024-05-19 18:19:06
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    long n,m,k; cin >> n >> m >> k;
    vector<long> arr(n+1);
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    vector<long> dp(n+1, LLONG_MAX/2);
    dp[0]=0;

    for(int i=1; i<=n; i++)
    {
        long min_size=INT32_MAX, max_size=-1;
        for(int j=1; j<=m; j++)
            if(i-j>=0)
            {
                min_size=min(min_size, arr[i-j+1]);
                max_size=max(max_size, arr[i-j+1]);
                dp[i]=min(dp[i], dp[i-j]+k+j*(max_size-min_size));
            }
    }
    cout << dp[n];
}

/*
    
*/