// https://www.acmicpc.net/problem/2744
// 2022-03-26 07:25:31 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    for(auto& c : s)
    {
        if(islower(c)) c=toupper(c);
        else c=tolower(c);
    }
    cout << s;
}

/*
    
*/