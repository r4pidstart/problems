#include<stdio.h>

int main(void)
{
    long long n,r, five=0, two=0;
    scanf("%lld %lld", &n, &r);

    // n! / n-r! * r!
    for(long long i=5; n>=i; i*=5)
        five+=n/i;
    for(long long i=5; (n-r)>=i; i*=5)
        five-=(n-r)/i;
    for(long long i=5; r>=i; i*=5)
        five-=r/i;

    for(long long i=2; n>=i; i*=2)
        two+=n/i;
    for(long long i=2; (n-r)>=i; i*=2)
        two-=(n-r)/i;
    for(long long i=2; r>=i; i*=2)
        two-=r/i;
    
    printf("%lld", five<two ? five:two);
}