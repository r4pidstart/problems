// https://www.acmicpc.net/problem/1069
// 2021-05-24 22:01:46 0ms
#include<bits/stdc++.h>
using namespace std;

int x,y,d,t, cnt=1;

int main(void)
{
    scanf("%d%d%d%d", &x,&y,&d,&t);
    double ans = sqrt(x*x + y*y);
    double dist_r=ans-d;
    while(true)
    {
        ans=min(ans, abs(dist_r) + (cnt++)*t);
        if(abs(dist_r) <= d)
        {
            ans=min(ans, (double)cnt*t);
            break;
        }
        dist_r=dist_r-d;
    }
    printf("%.11lf", ans);
}