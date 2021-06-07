#include<stdio.h>
#include<stdlib.h>

typedef struct line
{
    int a;
    int b;
}line;

int compare(const void *v1, const void *v2)
{
    struct line *a = (struct line *)v1;
    struct line *b = (struct line *)v2;

    if(a->a < b->a)
        return -1;
    else if(a->a > b->a)
        return 1;
    else
        return 0;
}

int main(void)
{
    int n, max=0;
    scanf("%d", &n);
    line arr[n];
    int memo[n];
    for(int i=0; i<n; i++)
        scanf("%d %d", &arr[i].a, &arr[i].b);

    qsort(arr, n, sizeof(line), compare);
    memo[0]=1;
    for(int i=1; i<n; i++)
    {
        int tmpmax=0;
        for(int j=0; j<i; j++)
        {
            if(arr[j].b<arr[i].b)
                if(tmpmax<memo[j])
                    tmpmax=memo[j];
        }
        memo[i]=tmpmax+1;
        if(max<memo[i])
            max=memo[i];
    }

    printf("%d", n-max);
}