// https://www.acmicpc.net/problem/1464
// 2024-03-31 12:24:43
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    string s; cin >> s;
    int n=s.length();
    
    string ans="";
    for(int i=0; i<n; i++)
    {
        if(!ans.size() or ans.front()>=s[i])
            ans=s[i]+ans;
        else
            ans+=s[i];
    }

    printf("%s", ans.c_str());
}

/*
    
*/