// https://www.acmicpc.net/problem/2864
// 2022-03-26 07:05:36 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string a,b; cin >> a >> b;
    replace(a.begin(), a.end(), '6', '5');
    replace(b.begin(), b.end(), '6', '5');
    cout << stoi(a)+stoi(b) << ' ';
    replace(a.begin(), a.end(), '5', '6');
    replace(b.begin(), b.end(), '5', '6');
    cout << stoi(a)+stoi(b) << ' ';
}

/*
    
*/