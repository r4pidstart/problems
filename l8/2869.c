// find the length of time the snail climb 
#include <stdio.h>

int main(void)
{
    int a,b,v,x;
    scanf("%d%d%d", &a,&b,&v);
    x=(v-b)/(a-b);
    printf("%d", x*(a-b)==(v-b) ? x : x+1);
}