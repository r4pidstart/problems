// https://www.acmicpc.net/problem/1212
// 2022-03-14 21:35:34 16ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    string ans="";
    if(s=="0") return !printf("0");
    for(int i=0; i<s.length(); i++)
    {
        ans+=!!(s[i]-'0'&4) + '0';
        ans+=!!(s[i]-'0'&2) + '0';
        ans+=!!(s[i]-'0'&1) + '0';
    }

    cout << ans.substr(ans.find('1'));
}

/*
    
*/