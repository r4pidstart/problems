#include<stdio.h>

int comp(int a, int b)
{
    return (a<b ? a:b);
}

int comp3(int a, int b, int c)
{
    return (a<b ? (a<c ? a:c):(b<c ? b:c));
}
int main(void)
{
    int n;
    scanf("%d", &n);
    int memo[n+1];
    
    memo[1]=0, memo[2]=1, memo[3]=1;

    for(int i=4; i<n+1; i++)
    {
        if(!(i%6))
        {
            memo[i]=comp3(memo[i/3], memo[i/2], memo[i-1])+1;
        }
        else if(!(i%3))
        {
            memo[i]=comp(memo[i/3], memo[i-1])+1;
        }
        else if(!(i%2))
        {
            memo[i]=comp(memo[i/2], memo[i-1])+1;
        }
        else
            memo[i]=memo[i-1]+1;
    }

    printf("%d", memo[n]);
}