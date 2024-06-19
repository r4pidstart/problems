// https://www.acmicpc.net/problem/1301
// 2024-06-16 17:21:09
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

long solution(int pprev, int prev, vector<int>& remain)
{
    static vector dp(6, vector(6, map<vector<int>, long>()));
    if(dp[pprev][prev].find(remain) != dp[pprev][prev].end())
        return dp[pprev][prev][remain];
    
    if(!accumulate(remain.begin(), remain.end(), 0))
        return dp[pprev][prev][remain]=1;
    
    long ret=0;
    for(int i=0; i<5; i++)
    {
        if(prev != i and pprev != i and remain[i])
        {
            remain[i]--;
            ret+=solution(prev, i, remain);
            remain[i]++;
        }
    }

    return dp[pprev][prev][remain]=ret;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    vector<int> arr(5);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    cout << solution(5, 5, arr);
}

/*
    
*/