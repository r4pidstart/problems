// https://www.acmicpc.net/problem/17386
// 2021-05-21 01:04:22 0ms
#include<bits/stdc++.h>
using namespace std;

typedef struct _point
{
    long long x,y;
}_point;

double ccw(_point a, _point b, _point c)
{
    return (a.x*b.y)+(b.x*c.y)+(c.x*a.y)-(b.x*a.y)-(c.x*b.y)-(a.x*c.y);
}
int main(void)
{
    _point a,b,c,d;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);

    double one=ccw(a,b,c)*ccw(a,b,d), two=ccw(c,d,a)*ccw(c,d,b);
    if(one <= 0 && two <= 0)
        if(one==two && one==0) // 일직선인경우
        {
            if(a.x > b.x)
                swap(a,b);
            if(c.x > d.x)
                swap(c,d);
            int start=max(a.x, c.x), end=min(b.x, d.x);
            if(start > end) // 구간이 겹치지 않을 경우
                printf("0");
            else // 구간이 겹칠 경우
                printf("1");       
        }
        else
            printf("1");
    else
        printf("0");
}

// a.x b.x c.x
// a.y b.y c.y