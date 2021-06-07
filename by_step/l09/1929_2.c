#include <stdio.h>
#include <math.h>

int is_prime (int n)
{
    int flag=0;
    if(n==1)
        return 0;
    for(int i=2, s=sqrt(n); i<=s; i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main(void)
{
    int m,n;
    scanf("%d%d",&m,&n);
    if(m==2 || m==1 || n==2)
        printf("2\n");
    if(m%2==0)
        m++;
    for(; m<=n; m+=2)
    {
        if(is_prime(m))
            printf("%d\n", m);
    }
}