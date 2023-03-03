// https://www.acmicpc.net/problem/2461
// 2023-03-03 20:55:50
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<pair<int,int> > arr(n*m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            int a; scanf("%d", &a);
            arr[i*m+j]={a, i};
        }
    sort(arr.begin(), arr.end());

    int ans=INT32_MAX;
    vector<int> cnt(n);
    int lo=0, hi=0, cnt2=0;
    while(lo<n*m and hi<n*m)
    {
        if(cnt2==n)
        {
            cnt2-=cnt[arr[lo++].second]-- == 1;
            if(cnt2==n) ans=min(arr[hi-1].first-arr[lo].first, ans);
        }
        else
            cnt2+=cnt[arr[hi++].second]++ == 0;
    }
    printf("%d", ans);
}

/*
    
*/