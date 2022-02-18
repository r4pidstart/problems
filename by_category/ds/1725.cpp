// https://www.acmicpc.net/problem/1725
// 2022-02-18 23:38:49 16ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> height(n+2);
    for(int i=1; i<=n; i++)
        scanf("%d", &height[i]);
    
    stack<int> stk;
    int ans=0;
    for(int i=0; i<=n+1; i++)
    {
        while(!stk.empty() and height[i] < height[stk.top()])
        {
            int now=stk.top(); stk.pop();
            ans=max(ans, (i-stk.top()-1)*height[now]);
        }
        stk.push(i);
    }
    printf("%d", ans);
}

/*
    
*/