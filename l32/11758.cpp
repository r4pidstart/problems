// https://www.acmicpc.net/problem/11758
// 2021-05-20 02:02:06 0ms
#include<bits/stdc++.h>
using namespace std;

typedef struct _point
{
    int x,y;
}_point;

double ccw(const _point one, const _point two, const _point three)
{
    return (one.x*two.y + two.x*three.y + three.x*one.y)-(two.x*one.y + three.x*two.y + one.x*three.y);
}

int main(void)
{
    _point a,b,c;
    scanf("%d%d%d%d%d%d", &a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
    if(ccw(a,b,c) < 0)
        printf("-1");
    else if(ccw(a,b,c) == 0)
        printf("0");
    else
        printf("1");
}
