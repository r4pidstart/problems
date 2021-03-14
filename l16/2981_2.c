#include<stdio.h>
#include<stdlib.h>
 
// time exceeded
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
    for(int i=0; i<n; i++)
        scanf("%d", &num[i]);
    qsort(num, n, sizeof(int), compare);

    for(int i=2; i<num[1]+1; i++)
    {
        int flag=0, tmp=num[0]%i;
        for(int j=0; j<n; j++)
        {
            if(tmp!=(num[j]%i))
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("%d ", i);
    }
}