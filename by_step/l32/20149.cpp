// https://www.acmicpc.net/problem/20149
// 2021-05-22 07:09:15 0ms
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> _point;

double ccw(_point a, _point b, _point c)
{   
    return (a.first*b.second+b.first*c.second+c.first*a.second)-(b.first*a.second+c.first*b.second+a.first*c.second);
}
int main(void)
{
    _point a,b,c,d;
    scanf("%lld%lld %lld%lld %lld%lld %lld%lld", &a.first, &a.second, &b.first, &b.second, &c.first, &c.second, &d.first, &d.second);
    
    if(a>b)
        swap(a,b);
    if(c>d)
        swap(c,d);      

    double one=ccw(a,b,c)*ccw(a,b,d), two=ccw(c,d,a)*ccw(c,d,b);
    if(one==two && two == 0)
    {      
        if(c<=b && d>=a) // 만날 경우
        {
            printf("1\n");
            double a1=(double)(b.second-a.second)/(b.first-a.first), a2=(double)(d.second-c.second)/(d.first-c.first);
            if(a.first==b.first)
                a1=DBL_MAX;
            if(c.first==d.first)
                a2=DBL_MAX;
            if(a1==a2) // 일직선
            {
                if((b==c) != (a==d)) // 한 점에서만 만나는 경우
                    if(b==c)
                        printf("%lld %lld", b.first, b.second);
                    else
                        printf("%lld %lld", a.first, a.second);
            }
            else // 꺾인 경우
            {
                double b1=a.second-a1*a.first, b2=c.second-a2*c.first;
                double x=(b2-b1)/(a1-a2);
                if(a.first==b.first) // y축에 평행한 직선
                    printf("%.11lf %.11lf", (double)a.first, a2*a.first+b2);
                else if(c.first==d.first)
                    printf("%.11lf %.11lf", (double)c.first, a1*c.first+b1);
                else
                    printf("%.11lf %.11lf", x, a1*x+b1);
            }
        }
        else
            printf("0");
    }
    else if(one<=0 && two<=0) // 한 점에서 만나는 경우
    {
        printf("1\n");
        double a1=(double)(b.second-a.second)/(b.first-a.first), a2=(double)(d.second-c.second)/(d.first-c.first);
        if(a.first==b.first)
            a1=DBL_MAX;
        if(c.first==d.first)
            a2=DBL_MAX;
        double b1=a.second-a1*a.first, b2=c.second-a2*c.first;
        double x=(b2-b1)/(a1-a2);
        if(a.first==b.first) // y축에 평행한 직선
            printf("%.11lf %.11lf", (double)a.first, a2*a.first+b2);
        else if(c.first==d.first)
            printf("%.11lf %.11lf", (double)c.first, a1*c.first+b1);
        else
            printf("%.11lf %.11lf", x, a1*x+b1);
    }
    else
        printf("0");
}