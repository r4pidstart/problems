// https://www.acmicpc.net/problem/14246
// 2022-06-05 01:33:13 12ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int k; scanf("%d", &k);

    arr.push_back(0);
    long long cnt=0, lo=0, hi=0, sum=0;
    while(hi<=n and lo<=hi)
    {
        if(sum <= k)
            sum+=arr[hi++];
        else
            cnt+=n-hi+1, sum-=arr[lo++];
    }
    printf("%lld", cnt);
}

/*
    
*/