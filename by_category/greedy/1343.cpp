// https://www.acmicpc.net/problem/1343
// 2021-11-23 05:39:33 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    int flag=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s.substr(i, 4) == "XXXX") s[i]=s[i+1]=s[i+2]=s[i+3]='A';
        if(s.substr(i, 2) == "XX") s[i]=s[i+1]='B';
        if(s[i]=='X') flag=1;
    }
    cout << (flag ? "-1":s);
}

/*
    
*/