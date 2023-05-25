#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int get_the_largest_idx(int arr[], int n, int s, int cnt)
{
    int max=0, idx=-1;
    
    for(int i=cnt; i<n; i++)
        if(arr[i] > max && s >= i-cnt) max=arr[i], idx=i;
    return idx;
}

int swap(int arr[], int s, int e)
{
    int ret=0, i=e;
    while(i != s)
    {
        ret++;
        int tmp=arr[i-1];
        arr[i-1]=arr[i];
        arr[i]=tmp;
        i--;
    }
    #ifdef LOCAL
        printf("-- %d %d\n", s, e);
        for(int i=0; i<5; i++)
            printf("%d ", arr[i]);
        printf("\n");
    #endif
    return ret;
}

int main(void)
{
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int s; scanf("%d", &s);

    int cnt=0;
    while(1)
    {
        int largest=get_the_largest_idx(arr, n, s, cnt);
        if(largest == -1) break;
        s-=swap(arr, cnt++, largest);
    }
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
}

/*

*/
