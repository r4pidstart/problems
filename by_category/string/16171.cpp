// https://www.acmicpc.net/problem/16171
// 2022-07-01 23:40:37
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    string s, target; cin >> s >> target;
    s.erase(remove_if(s.begin(), s.end(), [&](char c) { return isdigit(c); }), s.end());
    cout << (s.find(target) != string::npos);
}

/*
    
*/