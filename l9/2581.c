#include <stdio.h>
#include <math.h>

int is_prime (int n)
{
    int flag=0;
    for(int i=2, s=sqrt(n); i<=s; i++)
        if(n%i==0)
            flag++;
    if(n!=1 && flag==0)
            return 1;
    return 0;
}

int main(void)
{
    int m,n,min=0,N=0;
    scanf("%d%d", &m,&n);
    do
    {
        if(is_prime(n))
        {
            N+=n;
            min=n;
        }
    }
    while(m<n--);
    if(N==0)
        printf("-1");
    else
        printf("%d\n%d", N,min);
}