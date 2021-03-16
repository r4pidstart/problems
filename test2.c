#include<stdio.h>

int main(void)
{
    int n, count=0;
    scanf("%d", &n);
    long long tmp=1;
    for(int i=2; i<=n; i++)
    {
        long long tmp2=1, i_tmp=i;
        if(i_tmp%2==0 || i_tmp%5==0)
        {
            while(i_tmp%2==0 || i_tmp%5==0)
            {
                if(i_tmp%2==0)
                {
                    i_tmp/=2;
                    tmp2*=2;
                }
                else if(i_tmp%5==0)
                {
                    i_tmp/=5;
                    tmp2*=5;
                }
            }
        }
        tmp*=tmp2;
        while(tmp%10==0)
        {
            tmp/=10;
            count++;
        }
    }

    printf("%d", count);
}