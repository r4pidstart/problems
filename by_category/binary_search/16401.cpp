// https://www.acmicpc.net/problem/16401
// 2022-07-31 03:45:51
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int m,n; scanf("%d%d", &m, &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int s=1, e=1'000'000'000, ans=0;
    while(s<=e)
    {
        int mid=(s+e)/2;
        long long tmp=0;
        for(auto i : arr)
            tmp+=i/mid;
        
        if(tmp >= m)
            s=mid+1, ans=mid;
        else
            e=mid-1;
    }
    printf("%d", ans);
}

/*
    
*/