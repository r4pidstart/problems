#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int n,c,w; scanf("%d%d%d", &n, &c, &w);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    long ans=0;
    for(int i=1; i<=10000; i++)
    {
        long tmp=0;
        for(int j=0; j<n; j++)
        {
            long tmp2=1L*arr[j]/i*i*w - 1L*arr[j]/i*c;
            if(arr[j]%i==0) tmp2+=c;
            if(tmp2 > 0) tmp+=tmp2;
        }
        if(tmp > ans) 
            ans=tmp;
    }
    printf("%ld", ans);
}

/*

*/
