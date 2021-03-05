#include<stdio.h>

int res[8] = {0,};

int sequences(int n, int l, int i, int index)
{
    if(l==index)
    {
        for(int j=0; j<l; j++)
            printf("%d ", res[j]);
        printf("\n");
    }
    else
        for( ;i<=n; i++)
            {
                res[index]=i;
                sequences(n, l, i, index+1);
            }
}

int main(void)
{
    int n,m;
    scanf("%d%d", &n, &m);
    sequences(n, m, 1, 0);
}