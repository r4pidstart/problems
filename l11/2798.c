#include<stdio.h>

int main(void)
{
    int t,m,max=0;
    scanf("%d%d", &t, &m);
    int card[t];
    for(int i=0; i<t; i++)
    {
        scanf("%d", &card[i]);
    }
    for(int i=0; i<t; i++)
        for(int j=i+1; j<t; j++)
            for(int k=j+1; k<t; k++)
            {
                int sum=card[i]+card[j]+card[k];
                if(sum<=m && sum>max)
                    max=sum;
            }
    printf("%d", max);
}

