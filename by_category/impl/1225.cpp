// https://www.acmicpc.net/problem/1225
// 2022-03-14 21:46:59 76ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s1, s2; cin >> s1 >> s2;
    long long ans=0;
    for(auto a : s1)
        for(auto b : s2)
            ans+=(a-'0')*(b-'0');
    printf("%lld", ans);
}

/*
    
*/