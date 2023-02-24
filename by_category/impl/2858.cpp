// https://www.acmicpc.net/problem/2858
// 2023-02-25 05:49:54
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int r,b; scanf("%d%d", &r, &b);
    for(int i=1; i<=b; i++)
    {
        if(b%i==0 and (b/i+2)*(i+2)-b==r)
            return !printf("%d %d", b/i+2, i+2);
    }
}

/*
    
*/