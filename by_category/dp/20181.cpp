// https://www.acmicpc.net/problem/20181
// 2024-06-18 23:58:42
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

long solution(int now, const vector<pair<int, int> >& range)
{
    static vector<long> dp(range.size()+1, -1);
    if(now==range.size())
        return 0;
    if(dp[now] != -1)
        return dp[now];

    return dp[now]=max(solution(now+1, range), solution(range[now].first, range)+range[now].second);
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,k; cin >> n >> k;
    vector<int> arr(n+1);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    // range[start][i]={end, sum}, 
    vector<pair<int, int> > range(n, {n, 0});
    int lo=0, hi=0, sum=0;
    while(hi <= n)
    {
        if(sum >= k)
        {
            range[lo]={hi, sum-k};
            sum-=arr[lo++];
        }
        else
        {
            sum+=arr[hi++];
        }
    }

    cout << solution(0, range);
}

/*
    
*/