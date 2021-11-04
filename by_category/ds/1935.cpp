// https://www.acmicpc.net/problem/1935
// 2021-11-05 03:59:18 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    string s; cin >> s;
    vector<int> operand(n);
    for(int i=0; i<n; i++) 
        scanf("%d", &operand[i]);
    
    stack<double> stk;

    for(char&c : s)
        if(!(c=='+' or c=='-' or c=='*' or c=='/'))
            c=operand[c-'A'];

    for(char&c : s)
    {
        if(c=='+' or c=='-' or c=='*' or c=='/')
        {
            double a=stk.top(); stk.pop();
            double b=stk.top(); stk.pop();
            if(c=='+')
                stk.push(b+a);
            else if(c=='-')
                stk.push(b-a);
            else if(c=='*')
                stk.push(b*a);
            else if(c=='/')
                stk.push(b/a);
        }
        else
            stk.push(c);
    }

    printf("%.2lf", stk.top());
}

/*
    
*/