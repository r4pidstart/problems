#include<stdio.h>

int memo_n[41];
int memo_0[41]={1,0,};
int memo_1[41]={0,1,};

int fibonacci(int n)
{
    if(n<2)    
        return n;
    else
    {
        if(memo_n[n]==0)
        {
            memo_n[n]=fibonacci(n-1)+fibonacci(n-2);
            memo_0[n]=memo_0[n-1]+memo_0[n-2];
            memo_1[n]=memo_1[n-1]+memo_1[n-2];
        }
        return memo_n[n];
    }
}
int main(void)
{
    int T,n;
    scanf("%d", &T);
    fibonacci(40);
    while(T--)
    {
        scanf("%d", &n);
        printf("%d %d\n", memo_0[n], memo_1[n]);
    }
}