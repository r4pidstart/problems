#include<stdio.h>
#define max(x,y) ((x)>(y) ? (x):(y))
int main(void)
{
    int n, max_i=0; scanf("%d", &n);
    int arr[n+1]; arr[0]=0;

    for(int i=1; i<n+1; i++)
    {
        scanf("%d", &arr[i]);
        max_i=max(arr[i], max_i);
    }

    int stack[max_i], k=2, top=1; stack[0]=1;
    for(int i=1; i<n+1; i++)
    {
        if(top==0)
        {
            stack[top++]=k++;
        }
        if(stack[top-1]<arr[i])
        {
            while(k!=arr[i]+1)
            {
                stack[top++]=k++;
            }
            top--;
        }
        else // stack[top]<=arr[i]
        {
            while(stack[top-1]!=arr[i])
            {
                top--;
                if(top<0)
                {
                    printf("NO");
                    return 0;
                }
            }
            top--;
        }
    }

    k=2, top=1; stack[0]=1;
    printf("+\n");
    for(int i=1; i<n+1; i++)
    {
        if(top==0)
        {
            stack[top++]=k++;
            printf("+\n");
        }
        if(stack[top-1]<arr[i])
        {
            while(k!=arr[i]+1)
            {
                stack[top++]=k++;
                printf("+\n");
            }
            printf("-\n");
            top--;
        }
        else // stack[top]<=arr[i]
        {
            while(stack[top-1]!=arr[i])
            {
                printf("-\n");
                top--;
            }
            printf("-\n");
            top--;
        }
    }
}