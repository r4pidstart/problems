#include <stdio.h>

int main(void)
{
    int A,B;
    scanf("%d %d", &A, &B);
    int btmp=B,b100=0,b10=0,b1=0;
    for (int i=0; btmp>99; i++)
    {
        btmp-=100;
        b100++;
    }
    for (int i=0; btmp>9; i++)
    {
        btmp-=10;
        b10++;
    }
    b1=btmp;
    printf("%d\n", A*b1);
    printf("%d\n", A*b10);
    printf("%d\n", A*b100);
    printf("%d", A*B);
}