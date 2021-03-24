// https://www.acmicpc.net/problem/10816
// 2021-03-25 03:38:06 428ms
#include<iostream>
#include<algorithm>
using namespace std;

int arr[500000]={};
int n;

int upper_lower_bound(int start, int end, int target)
{
    int mid, t_start=start, t_end=end;

    while(t_start<t_end) // lower bound
    {
        mid=(t_start+t_end)/2;
        if(arr[mid]>=target)
        {
            t_end=mid;
        }
        else // if arr[mid]<target
        {
            t_start=mid+1;
        }
    }
    int lower=t_start;

    t_start=start, t_end=end;
    while(t_start<t_end) // upper bound
    {
        mid=(t_start+t_end)/2;
        if(arr[mid]>target)
        {
            t_end=mid;
        }
        else // if arr[mid]<=target
        {
            t_start=mid+1;
        }
    }
    int upper=t_start;

    if(upper==(n-1) && arr[n-1]==target)
        return upper-lower+1;
    else
        return upper-lower;
}

int main(void)
{
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr+n);

    int n2; scanf("%d", &n2);

    if(n==1)
    {
        while(n2--)
        {
            int tmp;
            scanf("%d", &tmp);
            if(arr[0]==tmp)
                printf("1");
            else
                printf("0");
        }
        return 0;
    }

    for(int i=0; i<n2; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        int result = upper_lower_bound(0,n-1, tmp);
        printf("%d ", result);
    }
}