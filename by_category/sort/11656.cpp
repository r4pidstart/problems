// https://www.acmicpc.net/problem/11656
// 2022-03-17 15:24:56 8ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    vector<string> ans;

    for(int i=0; i<s.length(); i++)
        ans.push_back(s.substr(i));

    sort(ans.begin(), ans.end());
    for(auto i : ans)
        cout << i << '\n';
}

/*
    
*/