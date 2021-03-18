#include<stdio.h>

int main(void)
{
    char tmp, stack[101], trash[101];
    while(1)
    {
        tmp=getchar();
        if(tmp=='.')
            break;
        int top=0, flag=0;
        do
        {
            if(tmp=='(' || tmp=='[')
                stack[top++]=tmp;
            else if(tmp==')')
            {
                if(stack[top-1]!='(')
                {
                    flag=1;
                    break;
                }
                else
                    top--;
            }
            else if(tmp==']')
            {
                if(stack[top-1]!='[')
                {
                    flag=1;
                    break;
                }
                else
                    top--;
            }
        } while (tmp=getchar(), tmp!='.');
        printf("%s\n", flag ? "no":(top ? "no":"yes"));
        if(flag==1)
            while(tmp=getchar(), tmp!='.');
        tmp=getchar();
    }
}
