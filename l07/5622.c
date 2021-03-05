#include <stdio.h>
#include <string.h>

int main(void)
{   
    char s[16];
    scanf("%s", s);
    int t=0, l=strlen(s);

    for (int i=0; i<l; i++)
    {
        if (s[i]>'V')
            t+=9;
        else if (s[i]>'S')
            t+=8;
        else if (s[i]>'O')
            t+=7;
        else if (s[i]>'L')
            t+=6;
        else if (s[i]>'I')
            t+=5;
        else if (s[i]>'F')
            t+=4;
        else if (s[i]>'C')
            t+=3;
        else
            t+=2;
        
        t++;
    }

    printf("%d\n", t);
}

// 123 456 789 101112 131415 16171819 202122 23242526
// abc def ghi j k l  m n o  p q r s  t u v  w x y z