#include <stdio.h>

int main(void)
{   
    int N;
    scanf("%d", &N);
    int arr[N*2+1];
    for (int i=1; i<N+1; i++)
        scanf("%d %d", &arr[2*i-1], &arr[2*i]);
    for (int i=1; i<N+1; i++)
        printf("%d\n", arr[2*i-1]+arr[2*i]);
}