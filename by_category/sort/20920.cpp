// https://www.acmicpc.net/problem/20920
// 2023-04-05 03:30:25
#include"bits/stdc++.h"
using namespace std;
#define int long

struct word
{
    string s;
    int cnt;
    bool operator<(const word& a) const
    {
        if(cnt != a.cnt)
            return cnt>a.cnt;
        else if(s.length() != a.s.length())
            return s.length()>a.s.length();
        else
            return s<a.s;
    }
};

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);
    int n,m; cin >> n >> m;
    map<string, int> ma;
    
    while(n--)
    {
        string s; cin >> s;
        if(s.length() >= m) ma[s]++;
    }

    vector<word> arr;
    for(auto it : ma)
        arr.push_back({it.first, it.second});
    sort(arr.begin(), arr.end());

    for(auto s : arr)
        cout << s.s << '\n';

}

/*
    
*/