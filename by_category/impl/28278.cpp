// https://www.acmicpc.net/problem/28278
// 2023-08-24 04:22:23
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    stack<int> stk;

    while(n--)
    {
        int cmd; scanf("%d", &cmd);
        switch (cmd)
        {
        case 1:
            int a; scanf("%d", &a);
            stk.push(a);
            break;
        case 2:
            if(stk.size()) printf("%d\n", stk.top()), stk.pop();
            else printf("-1\n");
            break;
        case 3:
            printf("%d\n", stk.size());
            break;
        case 4:
            printf("%d\n", stk.empty());
            break;
        case 5:
            if(stk.size()) printf("%d\n", stk.top());
            else printf("-1\n");
            break;
        default:
            break;
        }
    }
}

/*
    
*/