// https://www.acmicpc.net/problem/15976
// 2024-06-14 23:54:27
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    vector<pair<long, long> > arr1;
    for(int i=0; i<n; i++)
    {
        long a,b; cin >> a >> b;
        arr1.push_back({a, b});
    }

    int m; cin >> m;
    vector<pair<long, long> > arr2;
    for(int i=0; i<m; i++)
    {
        long a,b; cin >> a >> b;
        arr2.push_back({a, b});
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    
    int a,b; cin >> a >> b;
    vector<long> psum2(m+1);
    for(int i=0; i<m; i++)
        psum2[i+1]=psum2[i]+arr2[i].second;          
    
    long ans=0;
    for(int i=0; i<n; i++)
    {
        auto [idx, val]=arr1[i];

        // idx+a ~ idx+b까지의 누적합과 곱을 구하기
        auto it1=lower_bound(arr2.begin(), arr2.end(), make_pair(idx+a, LONG_MIN))-arr2.begin();
        auto it2=upper_bound(arr2.begin(), arr2.end(), make_pair(idx+b, LONG_MAX))-arr2.begin();

#ifdef LOCAL
        cout << it2-1 << ' ' << it1-1 << ' ' << val*(psum2[it2]-psum2[it1]) << '\n';
#endif
        ans+=val*(psum2[it2]-psum2[it1]);
    }
    cout << ans;
}

/*
    
*/