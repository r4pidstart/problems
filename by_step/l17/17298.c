// https://www.acmicpc.net/problem/17298
// 2021-03-19 02:19:03 328ms
#include<stdio.h>
#include<string.h>
int main(void)
{
    int n,tmp,top=1; scanf("%d", &n);
    int stack[n][2], res[n];
    memset(res, -1, sizeof(int)*n);
    scanf("%d" ,&stack[0][0]);
    stack[0][1]=0;
    for(int i=1; i<n; i++)
    {
        scanf("%d", &tmp);
        while(stack[top-1][0]<tmp && top!=0)
            res[stack[(top--)-1][1]]=tmp; // pop
        stack[top][0]=tmp;
        stack[top++][1]=i;
    }

    for(int i=0; i<n; i++)
        printf("%d ", res[i]);
}