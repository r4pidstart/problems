#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    char A[4], B[4], tmp;
    scanf("%s %s", A,B);
    
    tmp=A[0];
    A[0]=A[2];
    A[2]=tmp;

    tmp=B[0];
    B[0]=B[2];
    B[2]=tmp;

    printf("%s\n", (A)>atoi(B) ? A:B);
}