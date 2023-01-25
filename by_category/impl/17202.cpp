// https://www.acmicpc.net/problem/17202
// 2023-01-25 23:53:04
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s1, s2; cin >> s1 >> s2;
    string s="";
    for(int i=0; i<s1.length(); i++)
        s+=s1[i], s+=s2[i];
    while(s.size() != 2)
    {
        string new_s="";
        for(int i=0; i<s.length()-1; i++)
            new_s+=(s[i] - '0' + s[i+1]);
        s=new_s;
        for(auto &i : s)
            if(i > '9') i-=10;
    }
    cout << s;
}

/*
    
*/