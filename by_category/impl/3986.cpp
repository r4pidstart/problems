// https://www.acmicpc.net/problem/3986
// 2022-03-31 00:09:40 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,cnt=0; scanf("%d", &n);
    while(n--) 
    {
        string s; cin >> s;
        stack<char> stk;
        for(int i=0; i<s.length(); i++)
        {
            if(stk.size() and stk.top() == s[i])
                stk.pop();
            else
                stk.push(s[i]);
        }
        cnt+=stk.empty();
    } 
    printf("%d", cnt);
}

/*
    
*/