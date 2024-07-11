// https://www.acmicpc.net/problem/1662
// 2024-07-11 11:43:59
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    string s; cin >> s;
    stack<int> stk;
    long ans=0, now=1, zero=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            stk.push(s[i-1]-'0');
            if(!zero)
                ans-=now;
            if(s[i-1]-'0'!=0) now*=s[i-1]-'0';
            else zero++; 
        }
        else if(s[i]==')')
        {
            if(stk.top()!=0) now/=stk.top();
            else zero--;
            stk.pop();
        }
        else if(!zero)
            ans+=now;
    }
    cout << ans;
}

/*
    
*/
