// https://www.acmicpc.net/problem/24313
// 2023-03-29 03:05:25
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int a,b, c, n; scanf("%d%d%d%d", &a, &b, &c, &n);
    if(a*n+b <= c*n and a<=c) printf("1");
    else printf("0");
}

/*
    
*/