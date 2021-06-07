#include<stdio.h>

int main(void)
{
    int a,b,n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        int c=a, d=b, e;
        while(d)
        {
            e=c%d;
            c=d;
            d=e;
        }
        printf("%d\n", a*b/c); 
    }
}