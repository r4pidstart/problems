#include<stdio.h>
long long memo[1000001] ={0,1,2,};

long long func(int n)
{
    if(memo[n]==0)
        memo[n]=(func(n-1)+func(n-2))%15746;
    return memo[n];
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%lld", func(n));
}
