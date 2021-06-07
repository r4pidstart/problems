#include<stdio.h>

int res[8];

int sequences(int n, int r, int l)
{  
    if(r==l)
    {
        for(int i=0; i<r; i++)
            printf("%d ", res[i]);
        printf("\n");
        return 0;
    }

    for(int i=0; i<n; i++)
        if(r!=l)
        {
            res[l]=i+1;
            sequences(n,r,l+1);
        }
}

int main(void)
{
    int n,m;
    scanf("%d%d", &n,&m);
    sequences(n,m,0);
}