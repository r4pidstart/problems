#include<bits/stdc++.h>
using namespace std;

typedef struct _point
{
    int x,y;
}_point;

int main(void)
{
    _point a,b,c,d;
    scanf("%d%d%d%d%d%d%d%d", &a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
    // x축 기준으로 정렬
    if(a.x > b.x)
        swap(a,b);
    if(c.x > d.x)
        swap(c,d);
        
    // 겹치는 부분 구하기
    int start=max(a.x, c.x), end=min(b.x, d.x);
    if(start > end) // 구간이 겹치지 않을 경우
    {
        printf("0");
        return 0;
    }
    
    // 식 구하기 ax+b
    double a1=(float)(b.y-a.y)/(b.x-a.x), a2=(float)(d.y-c.y)/(d.x-c.x);
    double b1=a.y-a1*a.x, b2=c.y-a2*c.x;
    if(a1==a2 && b1==b2)
    {
        printf("1\n");
        // if(start==end)
        //     printf("%d %lf", start, a1*start+b1);
        return 0;
    }


    double x=(float)(b2-b1)/(a1-a2); // 교점(식이 동일하지 않은 이상 1차식 두개를 연립헀을 떄 나오는 교점은 하나.)
    // printf("1: %lfx+%lf\n2: %lfx+%lf\nstart: %d, end: %d, x=%lf\n\n", a1, b1, a2, b2, start, end, x);
    if(start <= x && x <= end)
    {
        printf("1\n");
        // printf("%lf %lf", x, a1*x+b1);
    }
    else
        printf("0");
}