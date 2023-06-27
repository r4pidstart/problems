// https://www.acmicpc.net/problem/1002
// 2023-06-28 03:03:54
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long x1,y1,r1, x2,y2,r2, d,sumr;
        scanf("%ld%ld%ld%ld%ld%ld", &x1,&y1,&r1, &x2,&y2,&r2);

        if(x1==x2 && y1==y2 && r1==r2)
        {
            printf("-1\n");
            continue;
        }

        d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        if((r1+r2)*(r1+r2)==d || abs(r1-r2)*abs(r1-r2)==d)
            printf("1\n");
        else if(abs(r1-r2)*abs(r1-r2)<d && d<(r1+r2)*(r1+r2))
            printf("2\n");
        else
            printf("0\n");
    }
}

/*
    
*/