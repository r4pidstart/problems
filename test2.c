#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned int sub;
    unsigned int n1;
    unsigned int n2;
    int j;
    int r1;
    int r2;

    int x=0;
    // for(int y=1; y<110000; y++)
    int y=101123;
    {
        int z=y-x;
        int i=sqrt(z);
        z=z-(i*i);
        int n=2*i-1;
        n+=(z%i ? z/i+1:z/i);

        r1=n;

        sub = y - x;
        n1 = 0; n2 = 0; j = 0;
        while (n1 < sub) {
            n2 += j * 2;
            n1 += ++j * 2;
        }
        r2= (n1 - sub < j ? j * 2 : j * 2 - 1);

        if (r2!=r1)
        {
            printf("%d %d / %d %d\n", x,y,r1,r2);
        }
    }
}