// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    stack<int> stk;

    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='(') stk.push(-1);
        else if(s[i]=='[') stk.push(-2);
        else if(s[i]==')')
        {
            // ( 가 나올 때 까지 pop
            int tmp=0;
            while(!stk.empty() and stk.top()!=-1)
            {
                if(stk.top() == -2) return !printf("0");
                tmp+=stk.top(); stk.pop();
            }
            if(tmp==0) tmp=1;
            if(stk.empty() or stk.top() != -1) return !printf("0");
            stk.pop();
            stk.push(tmp*2);
        }
        else if(s[i]==']')
        {
            // [ 가 나올 때 까지 pop
            int tmp=0;
            while(!stk.empty() and stk.top()!=-2)
            {
                if(stk.top() == -1) return !printf("0");
                tmp+=stk.top(); stk.pop();
            }
            if(tmp==0) tmp=1;
            if(stk.empty() or stk.top() != -2) return !printf("0");
            stk.pop();
            stk.push(tmp*3);
        }
    }

    // 스택에 남은 숫자 다 더하기
    int ans=0;
    while(!stk.empty())
        if(stk.top() < 0) return !printf("0");
        else ans+=stk.top(), stk.pop();

    printf("%d", ans);
}

/*
    
*/