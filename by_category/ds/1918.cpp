// https://www.acmicpc.net/problem/1918
// 2021-11-05 03:41:42 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s,ans; cin >> s;
    stack<char> stk;
    // 피연산자는 출력
    // 스택의 top이 우선순위가 낮은 연산자를 만날 때 까지 pop 후 연산자를 push
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='(') stk.push('(');
        else if(s[i]==')')
        {
            while(stk.top()!='(')
                ans+=stk.top(), stk.pop();
            stk.pop();
        }
        else if(s[i]=='*' or s[i]=='/')
        {
            while(!stk.empty() and (stk.top()=='*' or stk.top()=='/'))
                ans+=stk.top(), stk.pop();
            stk.push(s[i]);
        }
        else if(s[i]=='+' or s[i]=='-')
        {
            while(!stk.empty() and (stk.top()=='*' or stk.top()=='/' or stk.top()=='+' or stk.top()=='-'))
                ans+=stk.top(), stk.pop();
            stk.push(s[i]);
        }
        else
            ans+=s[i];
    }
    
    while(!stk.empty())
        ans+=stk.top(), stk.pop();

    cout << ans;
}

/*
    
*/