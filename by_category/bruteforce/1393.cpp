// https://www.acmicpc.net/problem/1393
// 2022-07-04 22:11:30 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int sx, sy; scanf("%d%d", &sx, &sy);
    int ex, ey, dx, dy; scanf("%d%d%d%d", &ex, &ey, &dx, &dy);

    int _gcd=gcd(dx, dy);
    dx/=_gcd, dy/=_gcd;

    double prev_dist=INT32_MAX; 
    int prev_x=ex, prev_y=ey;
    while(true)
    {
        double now_dist=(sx-ex)*(sx-ex)+(sy-ey)*(sy-ey);
        if(now_dist > prev_dist) break;
        else prev_dist=now_dist, prev_x=ex, prev_y=ey;
        ex+=dx, ey+=dy;
    }
    printf("%d %d", prev_x, prev_y);
}

/*
    
*/