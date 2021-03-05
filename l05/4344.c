#include <stdio.h>

int main(void)
{
    int N, n;
    scanf("%d", &N);
    while(N--)
    {
        scanf("%d", &n);
        int s[n], sum=0, p=0;
        for (int i=0; i<n; i++)
        {
            scanf("%d", &s[i]);
            sum += s[i];
        }
        double aver = sum / n;
        for (int i=0; i<n; i++)
        {
            if (s[i]>aver)
                p++;
        }
        printf("%.3f%%\n", (double)p/n*100);
    }
}