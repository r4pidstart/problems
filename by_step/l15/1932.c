#include<stdio.h>
int arr[501][501], T;

int comp(int a, int b)
{
    return a>b ? a:b;
}

int big(int T)
{
    int max=0;
    for(int i=0; i<T+1; i++)
        if(arr[T][i]>max)
            max=arr[T][i];
    return max;
}

int main(void)
{
    scanf("%d", &T);
    for(int i=0; i<T; i++)
        for(int j=0; j<i+1; j++)
            scanf("%d", &arr[i][j]);

    for(int i=1; i<T; i++)
        for(int j=0; j<i+2; j++)
            if(j==0)
                arr[i][0]=arr[i-1][0]+arr[i][0];
            else if(j==i+1)
                arr[i][j]=arr[i-1][j-1]+arr[i][j];
            else
                arr[i][j]=comp(arr[i-1][j-1],arr[i-1][j])+arr[i][j];

    printf("%d", big(T-1));
}