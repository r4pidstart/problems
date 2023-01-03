// https://www.acmicpc.net/problem/26518
// 2023-01-04 02:49:21
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    double b,c,a1,a2; scanf("%lf%lf%lf%lf", &b, &c, &a1, &a2);
    printf("%.9lf", ((double)b + sqrt(1L*b*b + 4*c)) / 2.);
}

/*
    
*/