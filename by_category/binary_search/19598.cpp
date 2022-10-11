// https://www.acmicpc.net/problem/19598
// 2022-10-12 00:06:09
#include"bits/stdc++.h"
using namespace std;

int check(int mid, vector<pair<int,int> >& arr)
{
    int cur=0;
    vector<int> room(mid);
    for(int i=0; i<arr.size(); i++)
    {
        int flag=0;
        for(int j=0; j<mid; j++)
        {
            if(room[cur] <= arr[i].first)
            {
                room[cur]=arr[i].second;
                flag=1;
                break;
            }
            cur=(cur+1)%mid;
        }
        if(!flag) 
            return 0;
    }
    return 1;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    sort(arr.begin(), arr.end());

    int lo=0, hi=100000, ans=100000;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(check(mid, arr))
        {
            ans=mid;
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
    printf("%d", ans);
}

/*
    
*/