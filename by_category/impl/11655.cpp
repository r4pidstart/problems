// https://www.acmicpc.net/problem/11655
// 2022-03-22 21:37:00 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;
    getline(cin, s);
    for(int i=0; i<s.length(); i++)
        if(islower(s[i]))
            s[i]=(s[i]-'a' + 13) % 26 + 'a';
        else if(isupper(s[i]))
            s[i]=(s[i]-'A' + 13) % 26 + 'A';
    cout << s;
}

/*
    
*/