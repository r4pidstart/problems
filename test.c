#include <stdio.h>
#include <math.h>

int test(int a, int b)
{
    if (b==0)
        return 1;
    int c=1;
    for (int i=0; i<b; i++)
        c *=a;
    return c;
}

int main(void)
{
    int n=0, target, target_digit=0;
    scanf("%d", &target);
    int tmp = target;
    while(tmp!=0)
    {
        target_digit++;
        tmp/=10;
    }
    int arr[target_digit];
    for (int total_digit=0; total_digit<target_digit; total_digit++)
    {
        for (int d=0; d<9; d++)
        {
            for (int now_digit=0; now_digit<=total_digit; now_digit++)
            {
                for (int first_digit=1; first_digit<10; first_digit++)
                {
                    arr[now_digit]=first_digit;
                    int tmp=0;
                    for (int i=0; i<=total_digit; i++)
                        tmp=arr[i]*test(10,i);
                    if (tmp>target)
                    {
                        break;
                    }
                    else
                    {
                        n++;
                    }
                }
            }
        }
    }
    printf("%d", n);
}
