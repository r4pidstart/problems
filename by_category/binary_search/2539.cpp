// https://www.acmicpc.net/problem/2539
// 2023-08-21 00:21:58
#include"bits/stdc++.h"
using namespace std;

int decision(int mid, vector<pair<int,int> >& arr, int color_paper_cnt)
{
    int covered=-1, cnt=0;
    
    for(auto& [x, y] : arr)
    {
        if(y>mid) return 0;
        if(covered < x) covered=x+mid-1, cnt++;
    }
    return color_paper_cnt>=cnt;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    int color_paper_cnt; scanf("%d", &color_paper_cnt);
    int k; scanf("%d", &k);
    vector<pair<int,int> > arr(k);
    for(int i=0; i<k; i++)
        scanf("%d%d", &arr[i].second, &arr[i].first);
    sort(arr.begin(), arr.end());
    
    int lo=0, hi=1000000, ans=1000000;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(mid, arr, color_paper_cnt))
            hi=mid-1, ans=mid;
        else
            lo=mid+1;
    }
    printf("%d", ans);
}

/*
    
*/