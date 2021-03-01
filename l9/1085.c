#include<stdio.h>

int abs(int n)
{
    if(n>0)
        n=-n;
    return n;
}
int main(void)
{
    int x,y,w,h,a,b;
    scanf("%d%d%d%d", &x,&y,&w,&h);
    a=(abs(w-x)<x ? (abs(w-x)):x);
    b=(abs(h-y)<y ? abs(h-y):y);
    printf("%d", a<b ? a:b);
}