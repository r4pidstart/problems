#include <stdio.h>

int main(void)
{   
    int n=1;
    char c=getchar(), prevc;

    if(c == ' ')
        n--;

    for(; c!='\n'; c=getchar())
    {
        if(c == ' ')
            n++;
        prevc=c;
    }

    if(prevc == ' ')
        n--;

    printf("%d\n", n);
} // 1116kb 16ms


