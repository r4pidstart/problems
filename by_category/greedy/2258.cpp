// https://www.acmicpc.net/problem/2258
// 2022-12-28 21:32:46
#include"bits/stdc++.h"
using namespace std;

bool custom_sort(pair<int,int> &a, pair<int,int> &b)
{
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<pair<int,int> > arr(n); // price / weight
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].second, &arr[i].first);
    sort(arr.begin(), arr.end(), custom_sort);

    int prev_sum=0;
    int lo=0, hi=0;
    while(true)
    {
        if(lo == n) break;
        while(++hi < n and arr[lo].first == arr[hi].first);
        int now_sum=0;
        for(int i=lo; i<hi; i++)
        {
            now_sum += arr[i].second;
            if(prev_sum + now_sum >= m)
            {
                // min(now_price * (hi - i), next_price)
                if(hi == n)
                    return !printf("%d", arr[i].first * (i-lo+1));
                else
                    return !printf("%d", min(arr[i].first * (i-lo+1), arr[hi].first));
            }
        }
        prev_sum += now_sum;
        lo = hi;
    }
    printf("-1");
}

/*
    
*/
