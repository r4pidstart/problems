#include <stdio.h>

int main(void)
{
    int array[11000] = {0};
    // self number
    for(int i=1; i<10000; i++)
    {
        int x=i, y=i;
        while(y != 0)
        {
            x= x+(y%10);
            y= y/10;
        }
        array[x]++;
    }
    for(int i=1; i<10000; i++)
    {
        if(array[i] == 0)
            printf("%d\n", i);
    }
}
