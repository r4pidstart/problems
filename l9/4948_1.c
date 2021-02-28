#include <stdio.h>
#include <math.h>

int is_prime (int n)
{

    if(n==1)
        return 0;
    for(int i=2, s=sqrt(n); i<=s; i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main(void)
{
    int n;
    while(scanf("%d", &n), n!=0)
    {
        int N=0;
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        for(int i=2*n-1; i>n; i-=2)
            if(is_prime(i))
                N++;
        printf("%d\n", N);
    }
}