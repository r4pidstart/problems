#include <stdio.h>

//wip

int exponent(int a, int b)
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

    int arr[target_digit], flag=0;
    for(int total_digit=1; total_digit<=target_digit; total_digit++)
    {
        for(int first_number=0; first_number<10; first_number++)
        {
            if(flag==-1)
                flag=0;
            for(int difference=1;;difference++)
            {
                if(flag==-1)
                {
                    break;
                }
                for(int now_digit=0, i=0, sum_difference; now_digit<total_digit; now_digit++, i++)
                {
                    if(flag==-1)
                    {
                        break;
                    }
                    sum_difference=i*difference;
                    if(first_number+sum_difference<10)
                    {
                        arr[now_digit]=first_number+i*difference;
                    }
                    else
                    {
                        flag=-1;
                    }
                }
                for(int tmp_digit=0; tmp_digit<total_digit; tmp_digit++)
                    tmp+=arr[tmp_digit]*exponent(10,tmp_digit);
                if(tmp>target)
                {
                    break;
                }
                else
                {
                    if(arr[total_digit-1] == 0)
                    {
                        break;
                    }
                    n++;
                }
            }
        }
    }

    printf("%d", n);
}