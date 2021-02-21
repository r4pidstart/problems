#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[100] = {0,};
    scanf("%s", s);

    for (int c = 'a'; c<='z'; c++)
    {
        int tmp = -1;
        for (int i=0; i<strlen(s); i++)
        {
            if (c == s[i])
            {
                tmp = i;
                break;
            }
        }
        printf("%d ", tmp);
    }
}