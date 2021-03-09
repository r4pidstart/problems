#include<stdio.h>


int comp(int a, int b)
{
    return (a<b ? a:b);
}

int main(void)
{
    int T, n;
    int arr[1001][3];
    scanf("%d", &T);
    for(int i=0; i<T; i++)
        scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
    
    for(int i=1; i<T; i++)
    {
        arr[i][0]=comp(arr[i-1][1], arr[i-1][2]) + arr[i][0];
        arr[i][1]=comp(arr[i-1][0], arr[i-1][2]) + arr[i][1];
        arr[i][2]=comp(arr[i-1][1], arr[i-1][0]) + arr[i][2];
    }

    printf("%d", arr[T-1][0]<arr[T-1][1] ? (arr[T-1][0]<arr[T-1][2] ? arr[T-1][0]:arr[T-1][2]):(arr[T-1][1]<arr[T-1][2] ? arr[T-1][1]:arr[T-1][2]));
}