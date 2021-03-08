#include<stdio.h>
#include<stdlib.h>

int *test;

int appand(int i)
{
    int N=0;
    while(test[N]!=0)
        N++;
    test[N]=i;
}


int main(void)
{
    test=malloc(4*5);
    appand(1);
    appand(2);
    appand(3);
    for(int i=0; i<6; i++)
        printf("%d ", test[i]);
}