// https://www.acmicpc.net/problem/7869
// 2021-05-23 23:16:39 0ms
#include<bits/stdc++.h>
using namespace std;

typedef pair<double, double> _point;

double get_dist(_point a, _point b)
{
    return sqrt((a.first-b.first)*(a.first-b.first)+((a.second-b.second)*(a.second-b.second)));
}

int main(void)
{
    _point a,b;
    double ra, rb, x, d; // x: 교점, d: 중심간 거리
    scanf("%lf%lf%lf", &a.first, &a.second, &ra);
    scanf("%lf%lf%lf", &b.first, &b.second, &rb);
    d=get_dist(a,b);
    x=((ra*ra)-(rb*rb)+(d*d))/(2*d);
    auto theta1=acos(x/ra), theta2=acos((d-x)/rb);
    if(d > ra+rb) // 교차 영역이 없을 때
        printf("0.000");
    else if(d+min(ra,rb)<=max(ra,rb)) // 큰 원이 작은 원에 포함될 때 
        printf("%.3lf", ra<rb ? ra*ra*M_PI:rb*rb*M_PI);
    else
    {
        double s1, s2;
        if(x<0) // 왼쪽 원 중심보다 왼쪽에 있을 경우
            s1=(ra*ra)*theta1+ra*sin(theta1)*abs(x), s2=(rb*rb)*theta2-rb*sin(theta2)*abs(d-x);
        else if(x>d) // 오른 쪽 원 중심보다 오른쪽에 있을 경우
            s1=(ra*ra)*theta1-ra*sin(theta1)*abs(x), s2=(rb*rb)*theta2+rb*sin(theta2)*abs(d-x);
        else // 일반적인 경우
            s1=(ra*ra)*theta1-ra*sin(theta1)*abs(x), s2=(rb*rb)*theta2-rb*sin(theta2)*abs(d-x);
        printf("%.3lf", s1+s2);
    }
}