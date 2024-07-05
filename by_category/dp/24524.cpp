// https://www.acmicpc.net/problem/24524
// 2024-06-27 11:26:04
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    string s; cin >> s;
    string t; cin >> t;
    vector<vector<int> > cnt(t.length()+1, vector<int>(s.length()+1));
    fill(cnt[0].begin(), cnt[0].end(), INT32_MAX/2);
    for(int idx=1; idx<=t.length(); idx++)
        for(int i=1; i<=s.length(); i++)
        {
            if(s[i-1]==t[idx-1])
                cnt[idx][i]=min(cnt[idx-1][i-1], cnt[idx][i-1]+1);
            else
                cnt[idx][i]=cnt[idx][i-1];
        }
    cout << cnt[t.length()][s.length()];
}

/*
    
*/