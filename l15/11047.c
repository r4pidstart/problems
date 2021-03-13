#include<stdio.h>

int main(void)
{
    int n, target, count=0;
    scanf("%d%d", &n, &target);
    int coin[n];
    for(int i=0; i<n; i++)
        scanf("%d", &coin[i]);
    
    for(int i=n-1; i!=-1; i--)
    {
        if(target==0)
            break;
        if(target/coin[i])
        {
            count+=target/coin[i];
            target%=coin[i];
        }
    }

    printf("%d", count);
}