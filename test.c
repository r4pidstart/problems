#include<stdio.h>

long long nCr(int n, int r)
{
    if(n-r==0 || r==0)
        return 1;
    if(n-r==1 || r==1)
        return n;
    long long tmp1=1, tmp2=1;
    for(int i=n+1; i>n-r+1; i--, tmp1=(tmp1*i)%10007);
    for(int i=r+1; i!=1; i--, tmp2=(tmp2*i)%10007);
    return tmp1/tmp2%10007;
}

int main(void)
{
    int n,r;
    scanf("%d%d", &n,&r);
    printf("%lld", nCr(n,r<n-r ? r:n-r));
}