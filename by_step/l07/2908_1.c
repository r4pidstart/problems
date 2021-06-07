#include <stdio.h>

int e(int x)
{
    int y = 1;
    while(x!=0)
    {
        y*=10;
        x--;
    }
    return y;
}

int main(void)
{   
    char A[3], B[3];
    int a=0,b=0;
    scanf("%s %s", A,B);

    for (int i=0; i<3; i++)
    {
        a += (A[i]-'0') * e(i);
        b += (B[i]-'0') * e(i);
    }
    
    printf("%d\n", a>b ? a:b);
}