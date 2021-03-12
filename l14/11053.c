#include<stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[1001]={0,}, memo[1001]={0,}, max=0;
    
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i+1]);

    for(int i=1; i<n+1; i++)
    {
        int tmpmax=0;
        for(int j=1; j<i+1; j++)
        {
            if(arr[i]>arr[j])
                if(tmpmax<memo[j])
                    tmpmax=memo[j];
        }
        memo[i]=tmpmax+1;
        if(max<memo[i])
            max=memo[i];
    }
    printf("%d", max);
}