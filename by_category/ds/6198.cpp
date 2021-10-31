// https://www.acmicpc.net/problem/6198
// 2021-10-30 21:31:57 16ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    stack<int> s;
    long long ans=0;
    while(n--)
    {
        int tmp; scanf("%d", &tmp);
        while(!s.empty() and s.top()<=tmp) s.pop();
        ans+=s.size();
        s.push(tmp);
    }
    printf("%lld", ans);
}

/*
    
*/