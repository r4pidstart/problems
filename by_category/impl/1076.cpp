// https://www.acmicpc.net/problem/1076
// 2022-03-14 21:09:24 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long ans=0;
    string s; 

    cin >> s;
    if(s=="black") ans=ans*10+0;
    else if(s=="brown") ans=ans*10+1;
    else if(s=="red") ans=ans*10+2;
    else if(s=="orange") ans=ans*10+3;
    else if(s=="yellow") ans=ans*10+4;
    else if(s=="green") ans=ans*10+5;
    else if(s=="blue") ans=ans*10+6;
    else if(s=="violet") ans=ans*10+7;
    else if(s=="grey") ans=ans*10+8;
    else if(s=="white") ans=ans*10+9;

    cin >> s;
    if(s=="black") ans=ans*10+0;
    else if(s=="brown") ans=ans*10+1;
    else if(s=="red") ans=ans*10+2;
    else if(s=="orange") ans=ans*10+3;
    else if(s=="yellow") ans=ans*10+4;
    else if(s=="green") ans=ans*10+5;
    else if(s=="blue") ans=ans*10+6;
    else if(s=="violet") ans=ans*10+7;
    else if(s=="grey") ans=ans*10+8;
    else if(s=="white") ans=ans*10+9;

    cin >> s;
    if(s=="black") ans=ans*1;
    else if(s=="brown") ans=ans*10;
    else if(s=="red") ans=ans*100;
    else if(s=="orange") ans=ans*1000LL;
    else if(s=="yellow") ans=ans*10000LL;
    else if(s=="green") ans=ans*100000LL;
    else if(s=="blue") ans=ans*1000000LL;
    else if(s=="violet") ans=ans*10000000LL;
    else if(s=="grey") ans=ans*100000000LL;
    else if(s=="white") ans=ans*1000000000LL;

    printf("%lld", ans);
}

/*
    
*/