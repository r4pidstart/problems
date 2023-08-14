// https://www.acmicpc.net/problem/28445
// 2023-08-15 04:08:24
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s[4];
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    vector<pair<string, string> > arr;
    for(string a : s)
        for(string b : s)
            arr.push_back({a, b});
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end())-arr.begin());
    for(auto& [a,b] : arr)
        cout << a << " " << b << '\n';
}

/*
    
*/