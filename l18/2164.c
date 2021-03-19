// https://www.acmicpc.net/problem/2164
// 2021-03-20 02:34:52 0ms
#include<stdio.h>
int main(void)
{
    int n; scanf("%d", &n);
    int front=0, rear=n, queue[1000000]={};
    for(int i=0; i<n; i++)
        queue[i]=i+1;
    while((rear-front)!=1)
    {
        front++;
        queue[rear++]=queue[front++];
    }
    printf("%d", queue[front]);
}