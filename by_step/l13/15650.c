#include<stdio.h>

int checklist[8] = {0,};
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
        if(checklist[i]==0)
        {
            if(l!=0)
                if(res[l-1]>i+1)
                    continue;
            res[l]=i+1;
            checklist[i]=1;
            sequences(n,r,l+1);
            checklist[i]=0;
        }
}

int main(void)
{
    int n,m;
    scanf("%d%d", &n,&m);
    sequences(n,m,0);
}