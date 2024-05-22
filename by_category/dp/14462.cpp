// https://www.acmicpc.net/problem/14462
// 2024-05-21 00:12:36
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    vector<pair<int, int> > arr1(n), arr2(n);
    for(int i=0; i<n; i++)
        cin >> arr1[i].first, arr1[i].second=i;
    for(int i=0; i<n; i++)  
        cin >> arr2[i].first, arr2[i].second=i;
    
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    // O(9*n)
    int idx=0;
    vector<vector<int> > arr(n);
    for(auto [i,loca] : arr1)
    {
        if(i-arr2[idx].first > 4)
            idx++;
        
        int tmp=idx;
        while(tmp < n and arr2[tmp].first-i < 5)
            arr[loca].push_back(arr2[tmp++].second);
            
        sort(arr[loca].begin(), arr[loca].end());
    }

    int ans=0;
    vector<vector<int> > dp(n, vector<int>(9));
    for(int i=0; i<n; i++)
        for(int j=0; j<arr[i].size(); j++)
        {
            dp[i][j]=1;
            for(int k=0; k<i; k++)
                for(int l=0; l<arr[k].size(); l++)
                    if(arr[i][j] > arr[k][l])
                    {
                        dp[i][j]=max(dp[i][j], dp[k][l]+1);
                    }
            ans=max(ans, dp[i][j]);
        }
    cout << ans;
}

/*
    
*/