#include<stdio.h>

int main(void)
{
    int n, tmp, max=0, min=1000000;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &tmp);
        if(tmp>max)
            max=tmp;
        if(tmp<min)
            min=tmp;
    }
    printf("%d", max*min);
}