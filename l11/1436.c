#include<stdio.h>
#include<string.h>

int main(void)
{
    int n,N=0;
    scanf("%d", &n);
    char s[100]={0,};
    for(int i=666; N!=n; i++)
    {
        int six=0;
        sprintf(s, "%d", i);
        for(int i=2, n=strlen(s); i<n; i++)
        {
            if(s[i]=='6' && s[i-1]=='6' && s[i-2]=='6')
                six++;
        }
        if(six)
            N++;
    }
    printf("%s", s);
}
