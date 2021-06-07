#include<stdio.h>

int main(void)
{   
    int num, tmp=0;
    char c;
    scanf("%d", &num);
    int res=num;
    while(scanf("%c", &c), c=='+' || c=='-')
    {
        scanf("%d", &num);
        if(c=='+')
            if(tmp!=0)
                tmp+=num;
            else
                res+=num;
        else
            if(tmp!=0)
            {
                res-=tmp;
                tmp=num;
            }
            else
                tmp+=num;
    }

    if(c!='-')
        res-=tmp;

    printf("%d", res);
}