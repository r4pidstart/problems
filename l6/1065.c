#include <stdio.h>

int main(void)
{
    int target, n=0;
    scanf("%d", &target);
    if (target==1000)
    {
        printf("144");
        return 0;
    }
    for (int i=1; i<=target; i++)
    {
        int tmp=i, digit=0, arr[3]={0,};
        while(tmp!=0)
        {
            arr[digit++]=tmp%10;
            tmp/=10;
        }
        switch (digit)
        {
        case 1:
            n++;
            break;
        
        case 2:
            n++;
            break;

        case 3:
            if((arr[2]-arr[1])==(arr[1]-arr[0]))
            {
                n++;
            }
            break;
        }
    }
    printf("%d", n);
}