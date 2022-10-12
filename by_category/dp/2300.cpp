// https://www.acmicpc.net/problem/2300
// 2022-10-13 12:32:24 96ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n+1);
    arr[0]={INT32_MIN, 0};
    for(int i=1; i<=n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second), arr[i].second=abs(arr[i].second);
    sort(arr.begin(), arr.end());

    vector<int> dp(n+1, 0);
    for(int i=1; i<=n; i++)
    {
        int cur=i;
        dp[i]=dp[i-1]+arr[i].second*2;
        int max_height=arr[i].second;
        while(--cur>0)
        {
            max_height=max(max_height, arr[cur].second);
            dp[i]=min(dp[i], dp[cur-1]+max(max_height*2, arr[i].first-arr[cur].first));
        }
    }
    printf("%d", dp[n]);
}

/*
    
*/