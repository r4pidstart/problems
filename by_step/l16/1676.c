#include<stdio.h>

int main(void)
{
    int n, count=0;
    scanf("%d", &n);
    for(int i=2; i<=n; i++)
    {
        int i_tmp=i;
        while(i_tmp%5==0)
            if(i_tmp%5==0)
            {
                i_tmp/=5;
                count++;
            }
    }
    printf("%d", count);
}