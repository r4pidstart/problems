// https://www.acmicpc.net/problem/22953
// 2022-09-21 00:34:06 932ms
#include"bits/stdc++.h"
using namespace std;

long test(int cnt, int limit, int n, vector<int> &arr)
{
    if(cnt == limit)
    {
        long lo=0, hi=LLONG_MAX/2, ans=LLONG_MAX/2;
        while(lo<=hi)
        {
            long tmp=(lo+hi)/2;

            __int128_t cnt=0;
            for(auto& i : arr)
                cnt+=tmp/i;
            
            if(cnt >= n)
                hi=tmp-1, ans=tmp;
            else
                lo=tmp+1;
        }
        return ans;
    }

    long ret=test(cnt+1, limit, n, arr);
    for(int i=0; i<arr.size(); i++)
        if(arr[i] != 1)
        {
            arr[i]--;
            ret=min(ret, test(cnt+1, limit, n, arr));
            arr[i]++;
        }
    return ret;
}

int main(void)
{
    int n,k,c; scanf("%d%d%d", &n, &k, &c);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    printf("%lld", test(0, c, k, arr));
}

/*
    
*/