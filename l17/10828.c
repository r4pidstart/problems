#include<stdio.h>
#include<string.h>

int comp(char *s1, char *s2)
{
    return !strcmp(s1,s2);
}

int main(void)
{
    int t; scanf("%d", &t);
    int top=0, stack[10001]={0,};
    while(t--)
    {
        char s[6];
        scanf("%s", s);
        if(comp(s, "push"))
        {
            scanf("%d", &stack[top++]);
        }
        else if(comp(s, "pop"))
        {  
            if(top==0)
                printf("-1\n");
            else
                printf("%d\n", stack[(top--)-1]);
        }
        else if(comp(s, "size"))
        {
            printf("%d\n", top);
        }
        else if(comp(s, "empty"))
        {
            if(top==0)
                printf("1\n");
            else
                printf("0\n");
        }
        else if(comp(s,"top"))
        {
            if(top==0)
                printf("-1\n");
            else
                printf("%d\n", stack[top-1]);
        }
    }
}