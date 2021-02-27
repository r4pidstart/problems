#include <stdio.h>
#include <math.h>

int main(void)
{
    int t, N=0, flag;
    scanf("%d", &t);
    while(t--!=0)
    {
        int n;
        scanf("%d", &n);
        flag=0;
        for(int i=2, s=sqrt(n); i<=s; i++)
            if(n%i==0)
                flag++;
            
        if(n!=1 && flag==0)
            N++;
    }
    printf("%d", N);
}