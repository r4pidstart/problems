// https://www.acmicpc.net/problem/26517
// 2023-01-01 23:52:16
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int k; scanf("%d", &k);
    int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d);
    if(1L*a*k+b == 1L*c*k+d)
        printf("Yes %ld", 1L*a*k+b);
    else
        printf("No");
}

/*
    
*/