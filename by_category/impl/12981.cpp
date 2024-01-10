// https://www.acmicpc.net/problem/12981
// 2024-01-09 01:09:18
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int r,g,b; scanf("%d%d%d", &r, &g, &b);
    int cnt=min({r,g,b});
    r-=cnt, g-=cnt, b-=cnt;
    if(r%3==1 and g%3==1) cnt++, r--, g--;
    if(g%3==1 and b%3==1) cnt++, g--, b--;
    if(r%3==1 and b%3==1) cnt++, r--, b--;
    cnt+=(r+2)/3 + (g+2)/3 + (b+2)/3;
    printf("%d", cnt);
}

/*
    
*/