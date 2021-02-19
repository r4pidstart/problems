#include <stdio.h>

int main(void)
{   
    int target, x, y, z, n=0;
    scanf("%d", &target);
    z=target;
    do
    {
        n++;
        z = z%10*10 + (z%10+z/10) % 10;
    }
    while (z!=target);
    printf("%d\n", n);
}