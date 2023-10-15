// https://www.acmicpc.net/problem/11320
// 2023-10-16 02:38:05
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int a,b; scanf("%d%d", &a, &b);
        int ans=0, prev=-1;
        while(a)
        {
            a-=b;
            ans+=prev+2;
            prev+=2;
        }
        printf("%d\n", ans);
    }
}

/*

*/