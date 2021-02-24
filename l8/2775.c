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
    int a,b,t;
    int arr[15][15] = {0, };
    for(int i = 0; i < 15; i++)
        arr[0][i] = i; 

    for(int i = 1; i < 15; i++) 
        for(int j = 1; j < 15; j++) 
            arr[i][j] = arr[i-1][j] + arr[i][j-1];

    scanf("%d", &t);
    while (t--!=0)
    {
    scanf("%d%d", &a, &b);
    printf("%d\n", test1(a,b), test2(a,b), arr[a][b]);
    }
}
