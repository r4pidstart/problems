#include <stdio.h>
#include <stdlib.h>

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
    int num[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &num[i]);
    }
    qsort(num, n, sizeof(int), compare);
    printf("%d %d", num[0], num[n-1]);
}