// https://www.acmicpc.net/problem/1439
// 2021-11-07 01:25:59 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin>>s;
    int ans=0, prev=-1;
    for(int i=0; i<s.length(); i++)
        if(prev != s[i]) ans++, prev=s[i];
    printf("%d", ans/2);
}

/*
    
*/