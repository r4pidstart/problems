#include <stdio.h>
#include <string.h>

int main(void)
{   
    char s[1000000];
    gets(s);
    int n=1, len=strlen(s);

    for (int i=0; i<len; i++)
    {
        if (s[i]==' ')
            n++;
    }

    if (s[0]==' ')
        n--;

    if (s[len-1]==' ')
        n--;

    printf("%d", n);
} // 1972kb 8ms