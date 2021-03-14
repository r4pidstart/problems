#include<stdio.h>
#include<stdlib.h>

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
    long long count=0;
    scanf("%d", &n);
    int time[n+1];
    for(int i=0; i<n; i++)
        scanf("%d", &time[i]);
    
    qsort(time, n, sizeof(int), compare);

    for(int i=0; i<n; i++)
        count+=time[i]*(n-i);

    printf("%lld", count);
}