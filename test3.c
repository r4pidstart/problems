#include<stdio.h>

int check_over_10(int *x)
{
    if(*x>9)
    {
        *x-=10;
        x++;
        *x+=1;
    }
    else
        return 0;
}

int main(void)
{
    int arr[3] = {3,11,3};
    check_over_10(&arr[0]);
    check_over_10(&arr[1]);
    return 0;
}