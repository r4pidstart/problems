#include<stdio.h>
#include<string.h>
#define max(x,y) (x)>(y) ? (x):(y)

int main(void)
{
    int n, max_w;
    scanf("%d %d", &n, &max_w);
    int memo[n+1][8], weigh[n+1], value[n+1];
    memset(memo, 0, (8*(n+1))*sizeof(int));

    for(int i=0; i<n; i++)
        scanf("%d%d", &weigh[i+1], &value[i+1]);
    
    for(int i=1; i<n+1; i++)
        for(int j=1; j<max_w+1; j++)
        {
            if(weigh[i]<=j)
                memo[i][j]=max(memo[i-1][j], memo[i-1][j-weigh[i]]+value[i]);
            else
                memo[i][j]=memo[i-1][j];
        }
    
    printf("%d", memo[n][max_w]);
}