#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int n; scanf("%d", &n);
    int arr[n], idx[n];

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]), arr[i]--;
    
    for(int i=0; i<n; i++)
        idx[arr[i]]=i;
    
    int ans[n];
    memset(ans, 0, sizeof(int)*n);
    for(int i=0; i<n; i++)
    {
        if(arr[i] != i)
        {
            int target_idx=idx[i];
            ans[arr[i]]+=(target_idx-i), ans[i]+=(target_idx-i);
            arr[target_idx]=arr[i];
            idx[arr[i]]=target_idx;
        }
    }
    
    for(int i=0; i<n; i++)
        printf("%d ", ans[i]);
}

/*
arr 0 2 4 1 3
idx 0 3 1 4 2
arr 0 1 4 2 3
idx 0 4 1 3 2
*/