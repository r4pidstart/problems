// https://www.acmicpc.net/problem/1114
// 2024-03-16 10:02:39
#include"bits/stdc++.h"
using namespace std;

pair<int,int> decision(int mid, int l, int c, const vector<int>& arr)
{
    int prv=0, cnt=0, last=0;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]-prv > mid)
            return make_pair(0, 0);
        if(i!=arr.size()-1 and arr[i+1]-prv > mid)
        {
            prv=arr[i], last=arr[i], cnt++;
        }
    }
    if(cnt<c)
        last=arr[arr.size()-2];
    return make_pair(cnt<=c, last);
}

int main(void)
{
    int l, k, c; scanf("%d%d%d", &l, &k, &c);
    vector<int> arr(k);
    for(int i=0; i<k; i++)
        scanf("%d", &arr[i]);
    for(int i=0; i<k; i++)
        arr[i]=l-arr[i];
    
    arr.push_back(l);
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end())-arr.begin());
    
    int lo=0, hi=l, ans=l;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(decision(mid, l, c, arr).first)
            hi=mid-1, ans=mid;
        else
            lo=mid+1;
    }
    auto sol=decision(ans, l, c, arr);
    printf("%d %d", ans, l-sol.second);
}

/*
    
*/