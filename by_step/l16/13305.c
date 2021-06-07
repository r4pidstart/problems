#include<stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    long long result=0, price, distance[100001]={0,}, prev_price=1000000000;
    for(int i=0; i<n-1; i++)
        scanf("%lld", &distance[i]);
    for(int i=0; i<n-1; i++)
    {
        scanf("%lld", &price);
        prev_price=prev_price<price ? prev_price:price;
        result+=prev_price*distance[i];
    }
    printf("%lld", result);
}