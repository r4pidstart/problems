// https://www.acmicpc.net/problem/15829
// 2022-03-25 00:19:38 0ms
#include<bits/stdc++.h>
using namespace std;

long long custom_pow(int i)
{
    long long ret = 1;
    while(i--)
        ret=ret*31 % 1234567891;
    return ret;
}

int main(void)
{
    string s; cin >> s >> s;
    long long ans=0;
    for(int i=0; i<s.length(); i++)
        ans=(ans + (s[i]-'a'+1) * custom_pow(i)) % 1234567891; 
    cout << ans;
}

/*
    
*/