#include <stdio.h>
#include <string.h>

int main(void)
{   
    char s[101];
    scanf("%s", s);
    int n=0, l=strlen(s);
    for (int i=0; i<l; i++)
    {
        if (s[i]=='=')
        {
            if (s[i-1]!='c' && s[i-1]!='z' && s[i-1]!='s')
                n++;
            if (s[i-1] == 'z')
            {
                if (s[i-2] == 'd')
                    n--;
            }
        }
        else if (s[i]=='-')
        {
            if (s[i-1]!='c' && s[i-1]!='d')
                n++;
        }
        else if (s[i]=='j')
        {
            if (s[i-1]!='l' && s[i-1]!='n')
                n++;
        }
        else
            n++;
    }

    printf("%d\n", n);
}