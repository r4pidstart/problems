// https://www.acmicpc.net/problem/2166
// 2021-05-20 01:50:06 0ms
#include<bits/stdc++.h>
using namespace std;

typedef struct _point
{
    long long x,y;
}_point;

double get_area(const _point one, const _point two, const _point three)
{
    return (one.x*two.y + two.x*three.y + three.x*one.y)-(two.x*one.y + three.x*two.y + one.x*three.y);
}

int main(void)
{
    int n; scanf("%d", &n);
    double sum=0;
    _point first, one, two;
    scanf("%lld%lld", &first.x, &first.y);
    scanf("%lld%lld", &two.x, &two.y);
    for(int i=2; i<n; i++)
    {
        swap(one, two); // 이전 점 기억하기
        scanf("%lld%lld", &two.x, &two.y);
        sum+=get_area(one,two,first);
    }
    printf("%.1lf", abs(sum/2));
}
