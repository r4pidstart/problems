// https://www.acmicpc.net/problem/1357
// 2022-03-25 00:05:44 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string a,b; cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string c=to_string(stoi(a) + stoi(b));
    reverse(c.begin(), c.end());
    cout << stoi(c);
}

/*
    
*/