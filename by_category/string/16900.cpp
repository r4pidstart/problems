// https://www.acmicpc.net/problem/16900
// 2021-06-26 22:51:51 20ms
#include<bits/stdc++.h>
using namespace std;

vector<int> get_pi(string s)
{
    int a=0, b=s.length();
    vector<int> pi(b,0);

    for(int i=1; i<b; i++)
    {
        while(a>0 && s[i]!=s[a])
            a=pi[a-1];
        if(s[a]==s[i])
            pi[i]=++a;
    }
    return pi;
}

int main(void)
{
    string s; int k;
    cin >> s >> k;
    vector<int> pi=get_pi(s);
    int s_len=s.length();
    long long ans=(long long)s_len+(long long)(s_len-pi[s_len-1])*(long long)(k-1);
    printf("%lld", ans);
}