// https://www.acmicpc.net/problem/17949
// 2021-10-30 23:14:31 36ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n; cin >> n;

    vector<long long> pow_dp(16,1);
    for(int i=1; i<16; i++) pow_dp[i]=pow_dp[i-1]*16;

    int cur=0;
    while(n--)
    {
        int length;
        string tmp; cin >> tmp;
        if(tmp=="char") length=2;
        else if(tmp=="int") length=8;
        else length=16;

        long long target=0;
        for(int i=0; i<length; i++)
            target+= ('a'<=s[cur+i] && s[cur+i]<='f') ? (s[cur+i]-'a'+10)*pow_dp[length-i-1]:(s[cur+i]-'0')*pow_dp[length-i-1];
        cout << target << " ";
        cur+=length;
    }
}

/*
    
*/