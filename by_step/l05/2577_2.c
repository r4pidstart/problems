#include <stdio.h>

int main(void)
{
    int num[100]={0,}, result[10]={0,};
    int a,b=1,n=0;
    for(int i=0; i<3; i++)
    {
        scanf("%d", &a);
        b=a*b;
    }
    int tmp=b;
    do
    {
        num[n]=tmp%10;
        n++;
        tmp=tmp/10;
    }
    while(tmp>10);
    num[n]=tmp;
    for(int i=0; i<n+1; i++)
    {
        result[num[i]]++;
    }
    for (int i=0; i<10; i++)
    {
        printf("%d\n", result[i]);
    }
}
