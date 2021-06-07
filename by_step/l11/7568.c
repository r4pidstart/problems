#include<stdio.h>

int main(void)
{
    int t;
    scanf("%d", &t);
    int x[t], y[t];
    for(int i=0; i<t; i++)
        scanf("%d%d", &x[i], &y[i]);

    for(int i=0; i<t; i++)
    {
        int tmp=1;
        for(int j=0; j<t; j++)
            if(x[j]>x[i] && y[j]>y[i])
                tmp++;
        printf("%d\n", tmp);
    }
}