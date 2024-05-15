// https://www.acmicpc.net/problem/17420
// 2024-05-13 14:56:44
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    vector<pair<long, long> > arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i].second;
    for(int i=0; i<n; i++)
        cin >> arr[i].first;
    
    sort(arr.begin(), arr.end());

    long prev_plan=0, prev_end=0, tmp=0, ans=0;
    for(int i=0; i<n; i++)
    {
        auto [plan, end]=arr[i];
        if(prev_plan != plan)
            prev_end=tmp, prev_plan=plan;

        if(plan > end)
            ans+=(plan-end+29)/30, end+=(plan-end+29)/30*30;
        
        if(prev_end > end)
            ans+=(prev_end-end+29)/30, end+=(prev_end-end+29)/30*30;
        
        tmp=max(tmp, end);
    }
    cout << ans;
}

/*
    
*/