// https://www.acmicpc.net/problem/1863
// 2023-02-11 01:41:21
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);

    int cnt=0;
    stack<int> stk;
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        while(stk.size() and stk.top() >= b)
        {
            if(stk.top() != b) cnt++;
            stk.pop();
        }
        if(b)
            stk.push(b);
    }
    printf("%lu", cnt+stk.size());
}

/*
    
*/