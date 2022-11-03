// https://www.acmicpc.net/problem/14426
// 2022-11-02 21:22:54
#include"bits/stdc++.h"
using namespace std;
#define int long

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);
    int n,m; cin >> n >> m;
    
    vector<string> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    int cnt=0;
    for(int j=0; j<m; j++)
    {
        string s; cin >> s;
        auto it=lower_bound(arr.begin(), arr.end(), s);
        if(it == arr.end()) continue;
        if(it->substr(0, s.size()) == s) cnt++;
    }
    cout << cnt;
}

/*
    
*/