#include<stdio.h>

int comp(int a, int b)
{
    return (a>b ? a:b);
}

int main(void)
{
    int n, step[301]={0,}, memo[301]={0,};
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &step[i+1]);

    memo[1]=step[1];
    memo[2]=step[1]+step[2];
    memo[3]=comp(step[3]+memo[1], step[3]+step[2]);

    for(int i=4; i<n+1; i++)
        memo[i]=comp(step[i]+memo[i-2], step[i]+step[i-1]+memo[i-3]);

    printf("%d", memo[n]);
}