// https://www.acmicpc.net/problem/23028
// 2023-08-28 02:43:49
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,a,b; scanf("%d%d%d", &n, &a, &b);
    // 66/130

    for(int i=0; i<8-n; i++)
    {
        int _max=6;
        int x,y; scanf("%d%d", &x, &y);
        int major=min(_max, x);
        _max-=major;

        int la=min(_max, y);
        a+=major*3;
        b+=major*3+la*3;

        if(a>=66 and b>=130)
            return !printf("Nice");
    }
    printf("Nae ga wae");
}

/*
    
*/