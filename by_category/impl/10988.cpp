// https://www.acmicpc.net/problem/10988
// 2022-03-18 23:22:38 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    for(int i=0; i<s.length()/2; i++)
        if(s[i] != s[s.length()-i-1])
            return !printf("0");
    printf("1");
}

/*
    
*/