// https://www.acmicpc.net/problem/2513
// 2023-07-09 12:04:50
#include"bits/stdc++.h"
using namespace std;

int sol(vector<pair<int,int> >& arr, int k)
{
    int prev_remain=0, ans=0, n=arr.size();
    for(int i=0; i<n; i++)
    {
        if(prev_remain)
        {
            if(prev_remain < arr[i].second)
                arr[i].second-=prev_remain, prev_remain=0;
            else
                prev_remain-=arr[i].second, arr[i].second=0;
        }

        while(arr[i].second > k)
            ans+=arr[i].first*2, arr[i].second-=k;
        
        if(arr[i].second)
            ans+=arr[i].first*2, prev_remain=k-arr[i].second;
    }
    return ans;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,k,s; scanf("%d%d%d", &n, &k, &s);
    vector<pair<int,int> > neg, pos;
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        if(a < s) // neg
            neg.push_back({s-a, b});
        else
            pos.push_back({a-s, b});
    }

    sort(neg.begin(), neg.end(), [](auto& a, auto& b){return a.first > b.first;});
    sort(pos.begin(), pos.end(), [](auto& a, auto& b){return a.first > b.first;});


    printf("%d", sol(neg, k) + sol(pos, k));
}

/*
    
*/