// https://www.acmicpc.net/problem/20291
// 2022-02-07 00:58:48 124ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(NULL)->sync_with_stdio(false);
    int n; cin >> n;
    map<string, int> m;
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        m[s.substr(s.find('.')+1)]++;
    }
    for(auto it : m)
        cout << it.first << ' ' << it.second << '\n';
}

/*
    
*/