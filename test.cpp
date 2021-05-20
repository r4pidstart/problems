#include<bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> pll;

double ccw(pll a, pll b, pll c)
{
    return (a.first*b.second)+(b.first*c.second)+(c.first*a.second)-(b.first*a.second)-(c.first*b.second)-(a.first*c.second);
}
int main(void)
{
    pll a,b,c,d;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &a.first,&a.second,&b.first,&b.second,&c.first,&c.second,&d.first,&d.second);

    double one=ccw(a,b,c)*ccw(a,b,d), two=ccw(c,d,a)*ccw(c,d,b);
    if(one <= 0 && two <= 0)
        if(one==two && one==0) // 일직선인경우
        {
            if(a > b)
                swap(a,b);
            if(c > d)
                swap(c,d);
            if(c<=b && a<=d)
                printf("1");
            else 
                printf("0");       
        }
        else
            printf("1");
    else
        printf("0");
}

// a.first b.first c.first
// a.second b.second c.second