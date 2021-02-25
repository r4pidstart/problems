#include<stdio.h>

int main(void)
{
    int w,n,t;
    for(scanf("%d", &w), t=w%5, n=w/5; t%3!=0; t+=5, n--) 
    {
        if(t>=w)
        {
            printf("-1");
            return 0;
        }
    }
    n+=t/3;
    printf("%d", n);
}