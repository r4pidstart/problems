// https://www.acmicpc.net/problem/2073
// 2023-07-12 04:12:27
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &k, &n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    
    sort(arr.begin(), arr.end(), [](auto a, auto b){return a.second>b.second;});
 
    vector<vector<int> > dp(2, vector<int>(k+1));
    dp[0][0]=INT32_MAX;

    for(int i=1; i<=arr.size(); i++)
        for(int j=0; j<=k; j++)
        {
            if(arr[i-1].first<=j)
                dp[i&1][j]=max(dp[i+1&1][j], min(dp[i+1&1][j-arr[i-1].first], arr[i-1].second));
            else
                dp[i&1][j]=dp[i+1&1][j];
        }
    printf("%d", dp[n&1][k]);
}

/*
    
*/