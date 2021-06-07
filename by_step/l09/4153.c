#include<stdio.h>

int main(void)
{
    int a,b,c,t;
    while(scanf("%d%d%d", &a,&b,&c), a!=b || b!=c || c!=0)
    {
        // a is the biggest
        if(b>a && b>c)
        {
            t=b;
            b=a;
            a=t;
        }
        else if(c>a && c>b)
        {
            t=c;
            c=a;
            a=t;
        }

        if(a*a==b*b+c*c)
            printf("right\n");
        else
            printf("wrong\n");
    }
}