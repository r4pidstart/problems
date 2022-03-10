// https://www.acmicpc.net/problem/10799
// 2022-03-11 02:21:57 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    stack<char> stk;
    int ans=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '(')
        {
            if(s[i+1] == ')')
                ans+=stk.size(), i++;
            else
                stk.push('('), ans++;
        }
        else
            stk.pop();
    }
    printf("%d", ans);
}

/*
    
*/