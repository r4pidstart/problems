// https://www.acmicpc.net/problem/27973
// 2024-02-21 01:28:21
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int q; scanf("%d", &q);
    long i=1;
    long alpha=1, beta=0;
    while(q--)
    {
#ifdef LOCAL
        long tmp=(i*alpha)+beta;
        printf("dbg - %ld\n", tmp);
#endif
        int a; scanf("%d", &a);
        if(a==0)
        {
            long b; scanf("%ld", &b);
            beta+=b;
        }
        else if(a==1)
        {
            long b; scanf("%ld", &b);
            alpha*=b;
            beta*=b;
        }
        else if(a==2)
        {
            long b; scanf("%ld", &b);
            i+=b;
        }
        else
        {
            printf("%ld\n", (i*alpha)+beta);
        }
    }
}

/*
    (i*a +b) *c +d * e + f
    (((i*a)+b)*c)+d

    alpha   / / beta
    (i*a*c) /+/ (b*c) + (d)
    (i*a*c) /+/ ((b*c) + (d)) * e
    (i*a*c) /+/ (b*c*e) + (d*e)
    (i*a*c) /+/ (b*c*e) + (d*e) + f
*/