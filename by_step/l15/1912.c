#include<stdio.h>
#include<string.h>
#define max(x,y) ( (x)>(y) ? (x):(y) )

int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[n+1], memo[n+1], biggest=-1000;
    memset(memo, 0, (n+1)*4);

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i+1]);
    
    memo[1]=arr[1];
    for(int i=1; i<n+1; i++)
    {
        memo[i]=max(memo[i-1]+arr[i], arr[i]);
        biggest=max(memo[i],biggest);
    }
    printf("%d", biggest);
}