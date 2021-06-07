#include<stdio.h>

int main(void)
{
    int a,b;
    scanf("%d%d",&a,&b);
    int c=a, d=b, e;
    while(d)
    {
        e=c%d;
        c=d;
        d=e;
    }
    printf("%d\n%d",c, a*b/c); 
}