#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i=2; i*i<=n; i++)
        if(n%i==0)
        {
            n/=i;
            printf("%d\n", i--);
        }
    if(n!=1)
        printf("%d", n);
}