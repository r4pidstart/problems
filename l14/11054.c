#include<stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[1001], memo1[1001], memo2[1001], max=0;
    
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i+1]);

    for(int i=1; i<n+1; i++)
    {
        int tmpmax1=0, tmpmax2=0;
        for(int j=1; j<=i; j++)
        {
            if(arr[i]>arr[j])
                if(tmpmax1<memo1[j])
                    tmpmax1=memo1[j];
            if(arr[n-i+1]>arr[n-j+1])
                if(tmpmax2<memo2[n-j+1])
                    tmpmax2=memo2[n-j+1];
        }
        memo1[i]=tmpmax1+1;
        memo2[n-i+1]=tmpmax2+1;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(arr[i]>arr[j])
                if(max<memo1[i]+memo2[j])
                    max=memo1[i]+memo2[j];
        }
    }

    if(memo1[n]>max)
        max=memo1[n];
    if(memo2[1]>max)
        max=memo2[1];

    printf("%d", max);
}