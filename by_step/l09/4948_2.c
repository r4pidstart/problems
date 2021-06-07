#include <stdio.h>

int is_prime (int n)
{
    if(n==1)
        return 0;
    for(int i=2; i*i<=n; i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main(void)
{
    // sqrt(246912)=496.9
    int n=497, table[246913]={0,};
    while(n--!=2)
    {
        if(is_prime(n))
            for(int i=2*n; i<246913; i+=n)
                table[i]=1;
    }
    while(scanf("%d", &n), n)
    {
        int N=0;
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        for(int i=2*n-1; n<i; i-=2)
        {
            if(!table[i])
                N++;
        }
        printf("%d\n", N);
    }
}