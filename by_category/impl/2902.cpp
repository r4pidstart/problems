// https://www.acmicpc.net/problem/2902
// 2022-01-02 02:29:19 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    string ans=""; ans+=s[0];
    for(int i=0; i<s.length()-1; i++)
        if(s[i]=='-') ans+=s[i+1];
    cout << ans;
}

/*
    
*/