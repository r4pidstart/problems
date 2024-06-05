// https://www.acmicpc.net/problem/24041
// 2024-06-04 22:52:32
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int decision(int mid, long k, long g, const vector<tuple<long, long, long> >& arr)
{
    long sum=0;
    vector<long> cand;

    for(auto [s, l, o] : arr)
    {
        long tmp=s*max(1L, mid-l);
        sum+=tmp;
        if(o)
            cand.push_back(tmp);
    }

    sort(cand.begin(), cand.end(), greater<>());
    for(int i=0; i<k and i<cand.size(); i++)
        sum-=cand[i];

    return sum<=g;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    long n,g,k; cin >> n >> g >> k;
    vector<tuple<long, long, long> > arr(n);
    for(auto& [a, b, c] : arr)
        cin >> a >> b >> c;
    
    long lo=0, hi=2e9, ans=0;
    while(lo<=hi)
    {
        long mid=(lo+hi)/2;
        if(decision(mid, k, g, arr))
            ans=mid, lo=mid+1;
        else
            hi=mid-1;
    }
    cout << ans;
}

/*

*/