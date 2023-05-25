#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    int arr[n+2];
    arr[0]=arr[n+1]=0;
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i+1]);
    
    int cnt=0;
    for(int i=1; i<=n; i++)
        if(!arr[i-1] && arr[i]) cnt++;
    
    while(m--)
    {
        int cmd; scanf("%d", &cmd);
        if(cmd==0)
            printf("%d\n", cnt);
        else
        {
            int a; scanf("%d", &a);
            if(arr[a]) continue;
            if(arr[a-1] && arr[a+1]) cnt--;
            else if(!arr[a-1] && !arr[a+1]) cnt++;
            arr[a]=1;
        }   
    }
}

/*

*/
