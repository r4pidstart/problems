// https://www.acmicpc.net/problem/7120
// 2022-11-24 04:02:39
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s; cin >> s;
    s.resize(unique(s.begin(), s.end())-s.begin());
    cout << s;
}

/*
    
*/
