#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    if(n+m-1>k) return !printf("NO");
    else printf("YES\n");

    int arr[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            printf("%d ", i+j+1);
        printf("\n");
    }
}

/*

*/
