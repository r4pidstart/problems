// finding minimum route in the honeycomb
#include <stdio.h>

int main(void)
{
    int x, n=1;
    scanf("%d", &x);
    while ((x-1)>0)
        x-=n++*6;
    printf("%d", n);
}