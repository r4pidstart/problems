// https://www.acmicpc.net/problem/1252
// 2023-04-09 02:37:09
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s1,s2;
    cin >> s1 >> s2;
    __int128_t a=0, b=0;
    for(char c : s1)
        a<<=1, a+=c-'0';
    for(char c : s2)
        b<<=1, b+=c-'0';
    
    a+=b;
    if(a==0)
        return cout<<'0', 0;
        
    string out="";
    while(a)
        out+=(a&1)+'0', a>>=1;
    reverse(out.begin(), out.end());
    assert(out.front() == '1');
    cout << out;
}

/*
    
*/