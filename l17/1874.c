// https://www.acmicpc.net/problem/1874
// 2021-03-18 22:56:47 28ms
#include<stdio.h>
int main(void)
{
    int n,tmp, top_stack=0, res_l=0, num=1; scanf("%d", &n);
    char res[200001]; int stack[100001];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &tmp);
        if(top_stack==0)
        {
            res[res_l++]='+';
            stack[top_stack++]=num++;
        }
        if(tmp>stack[top_stack-1])
        {
            while(tmp!=stack[top_stack-1])
            {
                if(num>tmp && stack[top_stack-1]<tmp)
                {
                    printf("NO");
                    return 0;
                }
                res[res_l++]='+';
                stack[top_stack++]=num++;
            }
            res[res_l++]='-';
            top_stack--;
        }
        else // tmp<=stack[top_stack-1]
        {
            while(tmp!=stack[top_stack-1])
            {
                res[res_l++]='-';
                top_stack--;
                if(top_stack==0)
                {
                    printf("NO");
                    return 0;
                }
            }
            res[res_l++]='-';
            top_stack--;
        }
    }
    for(int i=0; i<res_l; i++)
        printf("%c\n", res[i]);
    return 0;
}