// https://www.acmicpc.net/problem/21870
// 2022-07-11 23:07:53
#include"bits/stdc++.h"
using namespace std;

int get_ans(int s, int e, int val, vector<int>& arr)
{
    if(e-s == 1)
        return val + arr[s] + arr[e];
    else if(e-s == 0)
        return val + arr[s];

    int res1=arr[s], res2=arr[e], mid=(s+e)/2;
    for(int i=s; i<mid; i++)
        res1=gcd(res1, arr[i]);
    for(int i=mid; i<=e; i++)
        res2=gcd(res2, arr[i]);
    
    return max(get_ans(s, mid-1, val+max(res1, res2), arr), get_ans(mid, e, val+max(res1, res2), arr));
}

int main(void)
{
    int n; scanf("%d", &n);

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
       
    printf("%d", get_ans(0, n-1, 0, arr));
}

/*
    
*/