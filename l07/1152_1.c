#include <stdio.h>
#include <string.h>

int main(void)
{   
    char s[1000000];
    scanf("%[^\n]", s);
    int len=strlen(s), n=1;
    for(int i=0; i<len; i++)
    {
        if (s[i] == ' ')
            n++;
    }
    if (s[0] == ' ')
        n--;
    if (s[len-1] == ' ')
        n--;
    printf("%d\n", n);
} // 1972kb 12ms



