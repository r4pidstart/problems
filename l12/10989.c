#include<stdio.h>

int main(void)
{
    int n,t;
    scanf("%d", &n);
    int table[10001]={0,};
    for(int i=0; i<n; i++)
    {    
        scanf("%d", &t);
        table[t]++;
    }
    for(int i=1; i<10001; i++)
        while(table[i]--)
            printf("%d\n", i);
}
