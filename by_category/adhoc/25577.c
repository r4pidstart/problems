#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int comp(const void *a, const void *b)
{
    int **q=(int**)a, **w=(int**)b;
    return *q[0]-*w[0];
}

static int dfs(int now, int arr[], int n)
{
    static int visited[100001];

    if(now==arr[now]) return 0;
    if(visited[now]) return 0;

    visited[now]=1;
    if(visited[arr[now]]) return 0;
    else return dfs(arr[now], arr, n)+1;
}

int main(void)
{
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    int *sorted[n];
    for(int i=0; i<n; i++)
    {
        sorted[i]=malloc(sizeof(int)*2);
        sorted[i][0]=arr[i], sorted[i][1]=i;
    }
    qsort(sorted, n, sizeof(int)*2, comp);
    for(int i=0; i<n; i++)
        arr[sorted[i][1]]=i;
    
    int cnt=0;
    for(int i=0; i<n; i++)
        cnt+=dfs(i, arr, n);
        
    if(cnt==0) printf("0");
    else printf("%d", cnt);
}   
