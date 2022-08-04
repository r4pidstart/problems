// https://www.acmicpc.net/problem/3020
// 2022-08-05 01:55:20 72ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,h; scanf("%d%d", &n, &h);
    vector<vector<int> > arr(2);
    for(int i=0, a=0; i<n; i++, a^=1)
    {
        int b; scanf("%d", &b);
        arr[a].push_back(b);
    }
    sort(arr[0].begin(), arr[0].end());
    sort(arr[1].begin(), arr[1].end());

    int ans=INT32_MAX, cnt=0;
    for(int i=0; i<h; i++)
    {
        auto it1=upper_bound(arr[0].begin(), arr[0].end(), i);
        auto it2=upper_bound(arr[1].begin(), arr[1].end(), h-i-1);
        int tmp=0;
        if(it1 != arr[0].end())
            tmp+=arr[0].size() - (it1-arr[0].begin());
        if(it2 != arr[1].end())
            tmp+=arr[1].size() - (it2-arr[1].begin());

        if(ans > tmp)
            ans=tmp, cnt=0;
        if(ans == tmp)
            cnt++;
    }
    printf("%d %d", ans, cnt);
}

/*
    
*/