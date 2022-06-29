// https://www.acmicpc.net/problem/13397
// 2022-06-29 15:32:48 0ms
#include"bits/stdc++.h"
using namespace std;

int check(int m, int mid, vector<int>& arr)
{
    int cnt=1, range_min=arr[0], range_max=arr[0], ret=-1;
    for(int i=0; i<arr.size(); i++)
    {
        int next_min=min(range_min, arr[i]), next_max=max(range_max, arr[i]);
        if(next_max - next_min <= mid) range_min=next_min, range_max=next_max;
        else cnt++, ret=max(range_max - range_min, ret), range_min=arr[i], range_max=arr[i];
    }

    if(cnt <= m) return 100000 + max(range_max - range_min, ret);
    else return 0;
}

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(n);
    for(int i=0; i<n; i++)  
        scanf("%d", &arr[i]);
    
    int real_ans=INT32_MAX;
    int lo=0, hi=100000, ans=0;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        int tmp;
        if(tmp=check(m, mid, arr))
            ans=mid, hi=mid-1, real_ans=tmp%100000;
        else
            lo=mid+1;
    }
    printf("%d", real_ans);
}

/*
    
*/