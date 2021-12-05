// https://www.acmicpc.net/problem/2229
// 2021-12-05 23:31:26 312ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n), dp(n+1,0);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    
    for(int i=1; i<=n; i++)
        for(int j=0; j<i; j++)
            dp[i]=max(dp[i], (*max_element(&arr[j], &arr[i])-*min_element(&arr[j], &arr[i]) + dp[j]));
    
    printf("%d", dp[n]);
}

/*
    
*/