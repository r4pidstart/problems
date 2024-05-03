// https://www.acmicpc.net/problem/21319
// 2024-05-02 19:07:30
#include"bits/stdc++.h"
using namespace std;

int decision(int mid, const vector<int>& arr)
{
    int idx=lower_bound(arr.begin(), arr.end(), mid)-arr.begin();
    if(idx==arr.size())
        return 1;

    int win_cnt=idx;
    for(int i=idx+1; i<arr.size(); i++)
        if(arr[idx]+win_cnt > arr[i])
            win_cnt++;
        else
            return 0;
    return 1;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    if(n==1)
        return !printf("1");

    int lo=0, hi=1e9, tmp=1e9+1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(mid, arr))
            hi=mid-1, tmp=mid;
        else   
            lo=mid+1;
    }

    if(tmp > arr.back())
        return !printf("-1");

    vector<int> ans;
    int target=lower_bound(arr.begin(), arr.end(), tmp)-arr.begin();
    for(int i=target; i<n; i++)
        if(arr[i]>arr[i-1])
            ans.push_back(i+1);

    for(int i : ans)
        printf("%d ", i);
}

/*

*/