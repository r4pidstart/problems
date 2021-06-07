// https://www.acmicpc.net/problem/11866
// 2021-03-20 02:48:45 0ms
#include<stdio.h>
int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    int front=0, rear=n, queue[n*n];
    for(int i=0; i<n; i++)
        queue[i]=i+1;
    printf("<");
    n--;
    while(n--)
    {
        for(int i=1; i<k; i++)
            queue[rear++]=queue[front++]; // push(pop) * (k-1)
        printf("%d, ", queue[front++]); // pop
    }
    printf("%d>", queue[front]);
}