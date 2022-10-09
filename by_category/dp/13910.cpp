// https://www.acmicpc.net/problem/13910
// 2022-10-10 02:38:31 44ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(m);
    for(int i=0; i<m; i++)
        scanf("%d", &arr[i]);
    
    vector<int> possible;
    for(int i=0; i<m; i++)
    {
        for(int j=i+1; j<m; j++)
            possible.push_back(arr[i]+arr[j]);
        possible.push_back(arr[i]);
    }
    sort(possible.begin(), possible.end());
    possible.resize(unique(possible.begin(), possible.end())-possible.begin());

    vector<int> dp(n+1, INT32_MAX/2);
    dp[0]=0;
    for(int i=1; i<=n; i++)
    {
        for(auto target : possible)
        {
            if(target > i) break;
            dp[i]=min(dp[i], dp[i-target]+1);
        }
    }
    printf("%d", dp[n] == INT32_MAX/2 ? -1:dp[n]);
}

/*
    
*/