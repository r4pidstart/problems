// https://www.acmicpc.net/problem/5032
// 2023-02-21 05:36:26
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int e,f,c; scanf("%d%d%d", &e, &f, &c);
    int cnt=0;
    e+=f;
    while(e>=c)
        cnt+=e/c, e=e%c+e/c;
    printf("%d", cnt);
}

/*
    
*/