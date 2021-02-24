#include <stdio.h>

int main(void)
{
    int t,h,w,n;
    scanf("%d", &t);
    while(t--!=0)
    {
    scanf("%d%d%d", &h,&w,&n);
    printf("%d%02d\n", (n-1)%h+1, (n-1)/h+1);
    }
}