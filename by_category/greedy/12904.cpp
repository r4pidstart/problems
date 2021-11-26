// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s,t; cin >> s >> t;

    while(s.length() != t.length())
    {
        if(t.back()=='A') t.pop_back();
        else { t.pop_back(); reverse(t.begin(), t.end()); }
    }

    printf("%d", s==t ? 1:0);
}

/*
    
*/