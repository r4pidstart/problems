#include<stdio.h>
long long memo[101] ={0,1,1,1,2,2,};

long long func(int n)
{
    if(memo[n]==0)
        memo[n]=(func(n-1)+func(n-5));
    return memo[n];
}

int main(void)
{
    int T,n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        printf("%lld\n", func(n));
    }
}
