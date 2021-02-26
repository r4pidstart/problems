#include<stdio.h>
#include<math.h>

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--!=0)
    {
        int x,y,i;
        scanf("%d%d", &x,&y);
        int z=y-x;
        i=sqrt(z);
        z=z-(i*i);
        int n=2*i-1;
        n+=(z%i ? z/i+1:z/i);

        printf("%d\n", n);
    }
}