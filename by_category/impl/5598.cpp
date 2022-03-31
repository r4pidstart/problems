// https://www.acmicpc.net/problem/5598
// 2022-03-31 23:15:44 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    for(auto c : s)
        cout << (char)((c - 'A' + 26 - 3)%26 + 'A');
}

/*
    
*/