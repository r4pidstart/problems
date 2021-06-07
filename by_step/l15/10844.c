#include<stdio.h>
#define max 1000000000
long long sum(int n, long long memo[][10])
{
    long long tmp=0;
    for(int i=0; i<10; i++)
        tmp+=memo[n][i];
    return tmp % max;
}
int main(void)
{
    int n;
    scanf("%d", &n);
    long long memo[101][10]={0,};
    for(int i=1; i<10; i++)
        memo[1][i]=1;
    for(int i=2; i<n+1; i++)
        for(int j=0; j<10; j++)
        {
            if(j==0)
                memo[i][0]=memo[i-1][1]%max;
            else if(j==9)
                memo[i][9]=memo[i-1][8]%max;
            else
                memo[i][j]=(memo[i-1][j-1]+memo[i-1][j+1])%max;
        }

    printf("%lld", sum(n, memo));
}