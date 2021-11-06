// https://www.acmicpc.net/problem/1744
// 2021-11-07 02:39:52 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    priority_queue<int> pqN;
    priority_queue<int> pqP;
    int zero=0;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        if(a==0) zero++;
        else if(a<0) pqN.push(a);
        else pqP.push(a);
    }

    int ans=0, tmp=0;
    if(pqN.size()&1) // 홀수개면
        if(zero) pqN.pop();
        else tmp=pqN.top(), pqN.pop();
    while(!pqN.empty())
    {
        int a,b; a=pqN.top(), pqN.pop(), b=pqN.top(), pqN.pop();
        ans+=max(a*b, a+b);
    }
    
    while(!pqP.empty() and pqP.size()!=1)
    {
        int a,b; a=pqP.top(), pqP.pop(), b=pqP.top(), pqP.pop();
        ans+=max(a*b, a+b);
    }
    if(pqP.size()==1)
    {
        if(tmp) ans+=max(pqP.top()*tmp, pqP.top()+tmp);
        else ans+=pqP.top();
    }
    else if(tmp)
        ans+=tmp;

    printf("%d", ans);
}

/*
    
*/