#include<stdio.h>


int pactorial(int n)
{
    int res=1;
    for(int i=1; i<n+1; i++)
        res*=i;
    return res;
}

int combination(int n, int r)
{
    return pactorial(n)/pactorial(n-r)/pactorial(r);
}

int main(void)
{
    int n,r;
    scanf("%d%d", &n,&r);
    printf("%d", combination(n,r));
}