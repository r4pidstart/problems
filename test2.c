#include <stdio.h>
#include <math.h>

int main (int n)
{
    scanf("%d", &n);
    int flag=0;
    for(int i=2, s=sqrt(n); i<=s; i++)
        if(n%i==0)
            flag++;
    if(n!=1 && flag==0)
            printf("0");
    printf("1");
}