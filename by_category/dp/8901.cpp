// https://www.acmicpc.net/problem/8901
// 2023-09-08 00:44:34 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        int ab, bc, ca; scanf("%d%d%d", &ab, &bc, &ca);
        int ans=0;
        for(int ab_cnt=0; ab_cnt<=min(a, b); ab_cnt++)
            for(int bc_cnt=0; bc_cnt<=min(b-ab_cnt, c); bc_cnt++)
            {
                assert(a-ab_cnt>=0 and c-bc_cnt>=0);
                ans=max(ans, ab_cnt*ab+bc_cnt*bc+min(a-ab_cnt, c-bc_cnt)*ca);
            }
        printf("%d\n", ans);
    }
}

/*
    
*/