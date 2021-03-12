#include<stdio.h>

int comp3(int a, int b, int c)
{
    return (a>b ? (a>c ? a:c):(b>c ? b:c));
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int memo[10001][3]={0,};
    int arr[n+1];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i+1]);
    
    memo[1][0]=0;
    memo[1][1]=arr[1];
    memo[1][2]=arr[1];

    for(int i=2; i<n+1; i++)
    {
        memo[i][0]=comp3(memo[i-1][0], memo[i-1][1], memo[i-1][2]);
        memo[i][1]=memo[i-1][0]+arr[i];
        memo[i][2]=memo[i-1][1]+arr[i];
    }

    printf("%d", comp3(memo[n][0],memo[n][1],memo[n][2]));
}