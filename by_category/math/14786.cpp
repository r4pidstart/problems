// https://www.acmicpc.net/problem/14786
// 2023-07-27 03:45:45
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int a,b,c; scanf("%d%d%d", &a, &b, &c);

    double lo=0, hi=1000000;
    for(int i=0; i<100; i++)
    {
        double mid=(lo+hi)/2;
        if(a*mid+b*sin(mid)<=c) lo=mid;
        else hi=mid;
    }
    printf("%.9lf", lo);
}

/*
    
*/