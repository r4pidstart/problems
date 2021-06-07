#include<stdio.h>

int gcd(int a, int b)
{
    return b ? gcd(b,a%b):a;
}
long long nCr(int n, int r)
{
    if(n-r==0 || r==0)
        return 1;
    if(n-r==1 || r==1)
        return n;

    long long denominator=1, numerator=1;
    int deno[r], nume[r];
    for(int i=0; i<r; i++)
    {
        nume[i]=i+1;
        deno[i]=n-i;
    }

    for(int i=0; i<r; i++)
        for(int j=1; j<r; j++)
        {
            if(nume[j]!=1 && deno[i]!=1)
            {
                int tmp = gcd(nume[j], deno[i]);
                nume[j]/=tmp;
                deno[i]/=tmp;
            }
        }

    for(int i=0; i<r; i++)
    {
        denominator*=deno[i];
        numerator*=nume[i];
    }
    return (denominator/numerator);
}

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n,r;
        scanf("%d%d", &r,&n);
        printf("%lld\n", nCr(n,r<n-r ? r:n-r));
    }
}