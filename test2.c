#include <stdio.h>

int test1(int a, int b)
{
    int tmp=0;
    if (a==0)
        return b;
    for (int i=0; i<b; i++)
        tmp+=test1(a-1,i+1);
    return tmp;
}

int test2(int a, int b)
{
    if (a==0)
        return b;
    if (b==1)
        return 1;
    return test2(a-1,b) + test2(a,b-1);
}


int main(void)
{
    int arr[15][15] = {0, };
    for(int i = 0; i < 15; i++)
        arr[0][i] = i; 

    for(int i = 1; i < 15; i++) 
        for(int j = 1; j < 15; j++) 
            arr[i][j] = arr[i-1][j] + arr[i][j-1];

    for(int i=1; i<14; i++)
    {
        for(int j=1; j<14; j++)
        {
            if(test1(i,j) != arr[i][j] || test2(i,j) != arr[i][j])
                printf("%d %d %d\n", test1(i,j), test2(i,j), arr[i][j]);
            printf("%d, %d /",i,j);
        }
    }
}
