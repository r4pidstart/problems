#include <stdio.h>
#include <string.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    for(int k=0; k<N; k++)
    {
        int n;
        char s[20];
        scanf("%d %s", &n, s);
        for(int i=0; i<strlen(s); i++)
        {
            for(int j=0; j<n; j++)
                printf("%c", s[i]);
        }
        printf("\n");
    }
}