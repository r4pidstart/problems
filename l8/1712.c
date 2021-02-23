// finding break-even point by cost and price
#include <stdio.h>

int main(void)
{   
    int a,b,c,d;
    scanf("%d%d%d", &a,&b,&c);
    if (c<b)
    {
        printf("-1");
        return 0;
    }
    d=c-b;
    printf("%d", a/d+1);
}