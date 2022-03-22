// https://www.acmicpc.net/problem/7567
// 2022-03-22 22:07:33 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    int ans=10;
    for(int i=1; i<s.length(); i++)
        if(s[i-1] == s[i]) ans+=5;
        else ans+=10;
    printf("%d", ans);
}

/*
    
*/