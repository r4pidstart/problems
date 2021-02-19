#include <stdio.h>

int main(void)
{   
    int A,B;
    scanf("%d%d", &A, &B);
    while (A!=0 && B!=0)
    {
        printf("%d\n", A+B);
        scanf("%d%d", &A, &B);
    }
}