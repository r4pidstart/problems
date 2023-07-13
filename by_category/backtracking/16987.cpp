// https://www.acmicpc.net/problem/16987
// 2023-07-14 04:05:42
#include"bits/stdc++.h"
using namespace std;

int btrk(int idx, vector<pair<int, int> >& arr)
{
    if(idx==arr.size()) return 0;

    int ret=0, flag=0;
    for(int i=0; i<arr.size(); i++)
    {
        if(idx!=i and arr[i].first>0 and arr[idx].first>0)
        {
            flag=1;
            arr[i].first-=arr[idx].second;
            arr[idx].first-=arr[i].second;

            ret=max(ret, btrk(idx+1, arr)+(arr[i].first<=0)+(arr[idx].first<=0));

            arr[i].first+=arr[idx].second;
            arr[idx].first+=arr[i].second;
        }
    }
    if(!flag)
        ret=max(ret, btrk(idx+1, arr));
    
    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    
    printf("%d", btrk(0, arr));
}

/*
    
*/