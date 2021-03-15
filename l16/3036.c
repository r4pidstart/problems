#include<stdio.h>

int gcd(int a, int b)
{
    return b ? gcd(b,a%b):a;
}
int main(void)
{
    int n, first;
    scanf("%d", &n);
    scanf("%d", &first);
    while(n--!=1)
    {
        int tmp;
        scanf("%d", &tmp);
        int factor=gcd(tmp,first);
        printf("%d/%d\n", first/factor, tmp/factor);
    }
}