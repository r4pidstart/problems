// https://www.acmicpc.net/problem/2789
// 2022-04-18 01:21:12 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string target="CAMBRIDGE";
    string s; cin >> s;
    for(auto i : s)
    {
        if(target.find(i) == string::npos)
            cout << i;
    }
}

/*
    
*/