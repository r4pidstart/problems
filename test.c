#include<stdio.h>

int main(void)
{
    int n,tmp=0;
    char s[7]={0,};
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {   
        sprintf(s,"%d", i);

        if(s[0]+s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+i==n)
            break;
        tmp=0;
    }
    printf("%d", tmp);
}

