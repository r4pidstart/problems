#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        int arr[n], cnt=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
            if(arr[i]==2) cnt++;
        }
        
        int tmp=0;
        for(int i=0; i<n-1; i++)
        {
            if(arr[i]==2) cnt--, tmp++;
            if(cnt==tmp) 
            {
                printf("%d\n", i+1);
                goto for_exit;
            }
        }
        printf("-1\n");
        for_exit:;
    }
}