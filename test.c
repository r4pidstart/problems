#include <stdio.h>
#include <string.h>

int main(void)
{   
    char s[15];
    scanf("%s", s);
    int t=0, l=strlen(s);

    while (l!=0)
    {
        if (s[l-1]>'V')
            t+=9;
        else if (s[l-1]>'S')
            t+=8;
        else if (s[l-1]>'O')
            t+=7;
        else if (s[l-1]>'L')
            t+=6;
        else if (s[l-1]>'I')
            t+=5;
        else if (s[l-1]>'F')
            t+=4;
        else if (s[l-1]>'C')
            t+=3;
        else
            t+=2;
        l--;
    }

    printf("%d\n", t);
}

// 123 456 789 101112 131415 16171819 202122 23242526
// abc def ghi j k l  m n o  p q r s  t u v  w x y z