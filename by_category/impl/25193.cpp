// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n); n=0;
    string s; cin >> s;
    for(int i=0; i<s.length(); i++)
        if(s[i]!='C') n++;
    if(!n) printf("%d", s.length());
    else printf("%d", s.length()/(n+1));
}

/*
    
*/