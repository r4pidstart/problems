#include<stdio.h>

int test(char s[][2188], int n, int size)
{
    if (n==1)
        return 0;

        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
                if(i/(n/3)%3==1 && j/(n/3)%3==1)
                    s[i][j]=1;

    test(s, n/3, size);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    char s[2188][2188];

    test(s, n, n);

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            printf("%c", s[i][j]==0 ? '*':' ');
        printf("\n");
    }
}