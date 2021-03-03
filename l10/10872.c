#include<stdio.h>

int factorial(int n)
{
    if (n==0)
        return 1;
    n = n * factorial(n-1);
    return n;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    n=factorial(n);
    printf("%d", n);
}