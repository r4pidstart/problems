// https://www.acmicpc.net/problem/2343
// 2022-07-08 22:16:25
#include"bits/stdc++.h"
using namespace std;

int check(vector<int>& arr, int mid, int m)
{
    long long tmp=0, cnt=1;
    for(int i=0; i<arr.size(); i++)
        if(arr[i] > mid) return 0;
        else if(tmp+arr[i] > mid) tmp=arr[i], cnt++;
        else tmp+=arr[i];
    
    return cnt<=m;
}

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    long long s=0, e=100000*10000, ans=100000*10000;
    while(s<=e)
    {
        long long mid=(s+e)/2;
        if(check(arr, mid, m))
            e=mid-1, ans=mid;
        else
            s=mid+1;
    }
    printf("%d", ans);
}

/*
    
*/