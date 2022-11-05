// https://www.acmicpc.net/problem/4358
// 2022-11-06 03:59:14
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int cnt=0;
    map<string, int> m;
    string s;
    while(getline(cin, s))
        m[s]++, cnt++;
    for(auto i : m)
        cout << i.first << ' ' << fixed << setprecision(4) << 100.*i.second/cnt << '\n';
}

/*
    
*/