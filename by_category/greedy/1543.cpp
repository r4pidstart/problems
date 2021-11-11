// https://www.acmicpc.net/problem/1543
// 2021-11-11 23:31:08 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s1,s2; 
    getline(cin, s1);
    getline(cin, s2);
    int cnt=0;
    if(s1.length() < s2.length()) return !printf("0");
    for(int i=0; i<=s1.length()-s2.length(); i++)
    {
        if(s1.substr(i, s2.length())==s2) i+=s2.length()-1, cnt++;
    }
    cout << cnt;
}

/*
    
*/