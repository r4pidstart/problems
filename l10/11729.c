#include<stdio.h>

int move(int n, int f, int t, int v)
{
    if (n==1)
    {
        printf("%d %d\n", f, t);
        return 0;
    }
    move(n-1, f,v,t);
    printf("%d %d\n", f,t);
    move(n-1, v,t,f);
}

int main(void)
{
    int n, N=1;
    scanf("%d", &n);
    for(int i=n; i!=0; i--, N*=2);
    printf("%d\n", N-1);
    move(n, 1, 3, 2);
}

