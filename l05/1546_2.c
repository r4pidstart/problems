#include <stdio.h>

int main(void)
{
    int n, x, m=0;
    double sum=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &x);
        if (x>m)
            m=x;
        sum+=x;
    }
    printf("%f", sum/m*100/n);
}