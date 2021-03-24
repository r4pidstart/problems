// https://www.acmicpc.net/problem/1920
// 2021-03-25 02:13:12 76ms
#include<iostream>
#include<algorithm>
using namespace std;

int arr[100000]={};

int binary_search(int start, int end, int target)
{
    if(start > end)
            return 0;

    int mid=(start+end)/2;
    if(arr[mid]>target)
        return binary_search(start, mid-1, target);
    else if(arr[mid]<target)
        return binary_search(mid+1, end, target);
    else // if(arr[mid]==target)
        return 1;
}

int main(void)
{
    int n; scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr+n);

    int n2; scanf("%d", &n2);
    for(int i=0; i<n2; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        printf("%d\n", binary_search(0,n-1, tmp));
    }
}