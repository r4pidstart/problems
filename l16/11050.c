#include<stdio.h>

long long factorial(int a)
{
    if(a==0)
        return 1;
    long long tmp=a;
    while(a--!=1)
        tmp*=a;
    return tmp;
}

int main(void)
{
    int a,b;
    scanf("%d%d", &a,&b);
    printf("%lld", factorial(a)/(factorial(b)*factorial(a-b)));
}