// https://www.acmicpc.net/problem/2515
// 2023-07-26 02:18:34
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n, s; scanf("%d%d", &n, &s);

    vector<pair<int, int> > arr(1+n);
    for(int i=1; i<=n; i++)
        scanf("%d %d", &arr[i].first, &arr[i].second);
    
    sort(arr.begin(), arr.end());

    vector<int> dp(n+1);
    for(int i=1; i<=n; i++)
    {
        dp[i]=dp[i-1];
        // find largest painting that its height is less than arr[i].height-s+1
        auto it=lower_bound(arr.begin(), arr.end(), make_pair(arr[i].first-s+1, -1));
        if(it != arr.begin())
        {
            int prev_idx=distance(arr.begin(), prev(it));
            dp[i]=max(dp[i], dp[prev_idx]+arr[i].second);
        }
    }
    printf("%d", dp[n]);
}

/*
    
*/