#include<stdio.h>
#include<stdlib.h>
 
 int gcd(int a, int b)
 {
     return b? gcd(b, a%b) : a;
 }

int compare(const void *a, const void *b) 
{
    int num1 = *(int *)a; 
    int num2 = *(int *)b; 

    if (num1 < num2) 
        return -1;   
    
    if (num1 > num2) 
        return 1;   
    
    return 0;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int num[n], factor[1000]={0,}, count=0;
    for(int i=0; i<n; i++)
        scanf("%d", &num[i]);
    qsort(num, n, sizeof(int), compare);

    int tmp=num[1]-num[0];
    for(int i=2; i<n; i++)
        tmp=gcd(tmp, num[i]-num[i-1]);
    for(int i=1; i*i<=tmp; i++)
        if(tmp%i==0)
        {
            factor[count++]=i;
            if(i*i!=tmp)
                factor[count++]=tmp/i;
        }
    qsort(factor, count, sizeof(int), compare);
    for(int i=1; i<count; i++)
        printf("%d ", factor[i]);
}