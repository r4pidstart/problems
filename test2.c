#include <stdio.h>

int main(int a, int b)
{
    a=10;
    b=0;
    if (b==0)
        printf("%d", 1);
        return 1;
    int c=1;
    for (int i=0; i<b; i++)
        c *=a;
    printf("%d", c);
}