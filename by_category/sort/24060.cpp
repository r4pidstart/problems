// https://www.acmicpc.net/problem/24060
// 2022-09-18 09:57:14 116ms
#include"bits/stdc++.h"
using namespace std;

int k, cnt;

void merge(vector<int> &a, int p, int q, int r, vector<int> &tmp)
{
    int i=p, j=q+1, t=0;
    while (i<=q and j<=r)
    {
        if(a[i]<=a[j])
            tmp[t++]=a[i++]; //tmp[t]=a[i], t++, i++;
        else
            tmp[t++]=a[j++]; //tmp[t]=a[j], t++, j++;
    }
    while(i<=q)
        tmp[t++]=a[i++];
    while(j<=r)
        tmp[t++]=a[j++];
    i=p, t=0;
    while(i<=r)
    {
        cnt++;
        // printf("%d ", tmp[t]);
        if(cnt==k)
            exit(!printf("%d", tmp[t]));
        a[i++]=tmp[t++];
    }
}

void merge_sort(vector<int> &a, int p, int r, vector<int> &tmp)
{
    if(p<r)
    {
        int q=(p+r)/2;
        merge_sort(a, p, q, tmp);
        merge_sort(a, q+1, r, tmp);
        merge(a, p, q, r, tmp);
    }
}

int main(void)
{
    int n; scanf("%d%d", &n, &k);
    vector<int> arr(n), tmp(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    merge_sort(arr, 0, n-1, tmp);
    printf("-1");
}

/*
    
*/