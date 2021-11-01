// https://www.acmicpc.net/problem/23325
// 2021-11-02 00:49:45 F
#include<bits/stdc++.h>
using namespace std;

vector<int> memo(200001, INT32_MIN/2);

int dp(int now, string& s)
{
    if(now==-1) return INT32_MIN/2; // 불가능한 경우

    if(now==1) // 두개 남았을 때
    {
        if(s[now-1]=='+' and s[now]=='-') return 11;
        else return INT32_MIN/2; // 불가능
    }
    if(now==0) // 한개 남았을 때
    {
        if(s[now]=='+') return 10;
        if(s[now]=='-') return 1;
    }

    int& ret=memo[now];
    if(ret!=INT32_MIN/2) return ret;
    // 3*2 -> 6가지
    if(s[now-1]=='-' and s[now]=='-') ret=max(ret, dp(now-2, s)-1);
    if(s[now-1]=='-' and s[now]=='+') ret=max(ret, dp(now-2, s)-10);
    if(s[now-1]=='+' and s[now]=='-') ret=max(ret, dp(now-2, s)+1);
    if(s[now-1]=='+' and s[now]=='+') ret=max(ret, dp(now-2, s)+10);
    if(s[now-2]=='-' and s[now-1]=='+' and s[now]=='-') ret=max(ret, dp(now-3, s)-11);
    if(s[now-2]=='+' and s[now-1]=='+' and s[now]=='-') ret=max(ret, dp(now-3, s)+11);
    return ret;
}

int main(void)
{
    string s; cin >> s;
    printf("%d", dp(s.length()-1, s));
    return 0;
}

/*
    
*/