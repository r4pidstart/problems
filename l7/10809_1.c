#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[100] = {0,}, x[26] = {0,};
    scanf("%s", s);

    for (int i=0; i<strlen(s); i++)
    {
        if (x[s[i]-'a'] == 0)
            x[s[i]-'a']=i+1;
    }
    
    for (int i=0; i<26; i++)
    {
        printf("%d ", x[i]-1);
    }
}