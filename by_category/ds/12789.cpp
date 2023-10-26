// https://www.acmicpc.net/problem/12789
// 2023-10-27 04:30:03
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    int now=1;
    stack<int> stk;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        stk.push(a);

        while(stk.size() and stk.top()==now)
            stk.pop(), now++;
    }
    if(now==n+1)
        printf("Nice");
    else
        printf("Sad");
}

/*
    
*/