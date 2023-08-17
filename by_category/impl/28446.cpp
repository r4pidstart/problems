// https://www.acmicpc.net/problem/28446
// 2023-08-18 04:30:38
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int m; scanf("%d", &m);
    map<int, int> cabinet;
    while(m--)
    {
        int c; scanf("%d", &c);
        if(c==1)
        {
            int x,w; scanf("%d%d", &x, &w);
            cabinet[w]=x;
        }
        else
        {
            int w; scanf("%d", &w);
            printf("%d\n", cabinet[w]);
        }
    }
}

/*
    
*/