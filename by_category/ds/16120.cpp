// https://www.acmicpc.net/problem/16120
// 2022-12-30 20:47:56
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s;
    cin >> s;

    stack<char> stk;
    for(int i=0; i<s.length(); i++)
    {
        if(stk.size() >= 3 and s[i]=='P')
        {
            char c=stk.top();
            stk.pop();
            char b=stk.top();
            stk.pop();
            char a=stk.top();
            stk.pop();
            if(a!='P' or b!='P' or c!='A')
            {
                stk.push(a);
                stk.push(b);
                stk.push(c);
            }
        }
        stk.push(s[i]);
    }
    if(stk.size() == 1 and stk.top() == 'P')
        printf("PPAP");
    else
        printf("NP");
}

/*
    
*/