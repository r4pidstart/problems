#include <stdio.h>

int main(void)
{
    int n, m=0;
    double sum=0;
    scanf("%d", &n);
    int score[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &score[i]);
        if (score[i]>m)
            m=score[i];
    }
    for(int i=0; i<n; i++)
        sum+=((double)score[i]/m*100);
    printf("%f", sum/n);
}