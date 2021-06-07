#include<stdio.h>

int main(void)
{
    int t, tmp; scanf("%d", &t);
    int stack[100001]={0,}, top=0;
    int sum=0;
    while(t--)
    {
        scanf("%d", &tmp);
        if(tmp==0)
            top--;
        else
            stack[top++]=tmp;
    }
    for(int i=0; i<top; i++)
        sum+=stack[i];
    printf("%d", sum);
}
