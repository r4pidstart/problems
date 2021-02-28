#include <stdio.h>
#include <math.h>

int is_prime (int n)
{
    int flag=0;
    for(int i=2, s=sqrt(n); i<=s; i++)
        if(n%i==0)
            return 0;
    if(n!=1)
            return 1;
}

int main(void)
{
    int m,n;
    scanf("%d%d",&m,&n);
    while(m<=n)
    {
        if(is_prime(m))
            printf("%d\n", m++);
        else
            m++;
    }
}