#include<stdio.h>

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
    int s=100, table[10001]={0,};
    while(s--!=1)
    {
        if(is_prime(s))
            for(int i=2*s; i<10001; i+=s)
                table[i]=1;
    }
    int n,t;
    scanf("%d", &t);
    while(t--!=0)
    {
        scanf("%d", &n);
        int i=n/2-1, j;
        while(1)
        {
            while(table[++i]);
            j=n-i;
            if(!table[j])
                break;
        }
            printf("%d %d\n", j,i);
    }
}