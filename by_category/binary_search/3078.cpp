// https://www.acmicpc.net/problem/3078
// 2022-09-24 01:06:14 256ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<vector<int> > arr(21);
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        arr[s.length()].push_back(i+1);
    }

    long ans=0;
    for(auto arr:arr)
    {
        for(int i=0; i<arr.size(); i++)
        {
            auto it = lower_bound(arr.begin(), arr.end(), arr[i]+k);
            if(it==arr.end() || *it > arr[i]+k) it--;
            if(*it <= arr[i]+k)
                ans+=it-arr.begin()-i;
        }
    }
    printf("%ld", ans);
}

/*
    
*/