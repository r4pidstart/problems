// https://www.acmicpc.net/problem/20366
// 2022-12-27 15:49:26
#include"bits/stdc++.h"
using namespace std;

inline int dup_check(pair<int,int>& a, pair<int,int>& b)
{
    return (a.first == b.first || a.first == b.second || a.second == b.first || a.second == b.second);
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    vector<pair<int,pair<int,int> > > cand; 
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            cand.push_back({arr[i]+arr[j], {i, j}});
    sort(cand.begin(), cand.end());

    // int lo=0, hi=1e9, ans=1e9;
    // while(lo<=hi)
    // {
    //     int mid=(lo+hi)/2;
    //     if(check(mid, cand))
    //         hi=mid-1, ans=mid;
    //     else
    //         lo=mid+1;
    // }

    int l=0, r=0, ans=2e9;
    while(r < cand.size())
    {
        assert(l<=r);
        if(cand[l].second.first == cand[r].second.first)
            r++;
        else
        {
            ans = min(ans, dup_check(cand[l].second, cand[r].second) ? INT32_MAX : cand[r].first - cand[l].first);
            l++;
        }
    }
    printf("%d", ans);
}

/*
    
*/