// https://www.acmicpc.net/problem/1669
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    long x,y; scanf("%ld%ld", &x, &y);
    long dif=y-x;

    if(dif==0) return !printf("0");
    long top=1;
    while(true)
    {
        if(top*(top+1)-top > dif) break;
        top++;
    }
    top--;
    printf("%ld", top*2-1 + (dif-(top*(top+1)-top) + top-1) / (top));
}

/*
dif1
1211
3+(5-4 + top-1)/top
1 1 1
1 2 1
1 2 1 1
*/