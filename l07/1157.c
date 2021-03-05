#include <stdio.h>
#include <string.h>

int main(void)
{   
    char s[1000000];
    int x[122], max=0, y=-1, flag=0, z;
    scanf("%s", s);
    
    int len=strlen(s);
    for (int i=0; i<len; i++)
        x[s[i]]++;

    for (int i=0; i<26; i++)
    {
        z = x[i+'A']+x[i+'a'];
        if(max<=z)
        {
            y = i;
            flag=0;
            if(max==z)
                flag=-1;
            max=z;
        }
    }
    if(flag==-1)
        printf("?");
    else
        printf("%c", (char)y+'A');
} // 1976kb 12ms

#include <stdio.h>
#include <string.h>

int main(void)
{   
    char s[1000000];
    int x[122], max=0, y=-1, flag=0, z;
    fread(s, 1, 1000000, stdin);
    
    int len=strlen(s);
    for (int i=0; i<len; i++)
        x[s[i]]++;

    for (int i=0; i<26; i++)
    {
        z = x[i+'A']+x[i+'a'];
        if(max<=z)
        {
            y = i;
            flag=0;
            if(max==z)
                flag=-1;
            max=z;
        }
    }
    if(flag==-1)
        printf("?");
    else
        printf("%c", (char)y+'A');
} // 1972kb 0ms https://doocong.com/algorithm/fast-input-mmap/ https://www.acmicpc.net/blog/view/56