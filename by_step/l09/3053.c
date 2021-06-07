#include<stdio.h>
#include<math.h>
#define _USE_MATH_DEFINES

int main(void)
{
    int r;
    scanf("%d", &r);
    printf("%f\n%f", r*r*M_PI, (double)2*r*r);
}