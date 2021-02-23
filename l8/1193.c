// find the fraction in array
#include <stdio.h>

int main(void)
{
    int n, sum=1, f1, f2;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        n-=i;
        sum++;
    }
    f1 = 1;
    f2 = sum-1;
    while(n-->1)
    {
        f1++;
        f2--;
    }

    printf("%d/%d", sum%2!=1 ? f2:f1 , sum%2!=1 ? f1:f2);
}