// https://www.acmicpc.net/problem/12002
// 2024-02-22 23:53:10
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    
    sort(arr.begin(), arr.end());

    vector<pair<int,int> > cand;
    // get the leftmost six point
    {
        int cnt=0;
        for(auto it=arr.begin(); cnt<6 and it != arr.end(); it++, cnt++)
            cand.push_back(*it);  
    }
    // get the rightmost *
    {
        int cnt=0;
        for(auto it=arr.rbegin(); cnt<6 and it != arr.rend(); it++, cnt++)
            cand.push_back(*it);  
    }

    sort(arr.begin(), arr.end(), [](auto a, auto b) -> bool
    {
        if(a.second == b.second)
            return a.first<b.first;
        else return a.second<b.second;
    });  

    // get the highest *
    {
        int cnt=0;
        for(auto it=arr.begin(); cnt<6 and it != arr.end(); it++, cnt++)
            cand.push_back(*it);  
    }
    // get the lowest *
    {
        int cnt=0;
        for(auto it=arr.rbegin(); cnt<6 and it != arr.rend(); it++, cnt++)
            cand.push_back(*it);  
    }

    // O(24C3*n)
    vector<int> combi(24, 1);
    fill(combi.begin()+3, combi.end(), 0);

    long ans=LONG_MAX;
    do
    {
        int lx=INT32_MAX, hx=0, ly=INT32_MAX, hy=0;
        vector<pair<int,int> > selected;
        for(int i=0; i<24; i++)
            if(combi[i]) selected.push_back(cand[i]);

        for(int i=0; i<n; i++)
        {
            if(arr[i] != selected[0] and arr[i] != selected[1] and arr[i] != selected[2])
                lx=min(lx, arr[i].first), hx=max(hx, arr[i].first), ly=min(ly, arr[i].second), hy=max(hy, arr[i].second);
        }
        ans=min(ans, 1L*(hx-lx)*(hy-ly));
    } while (prev_permutation(combi.begin(), combi.end()));
    printf("%ld", ans);
}

/*
    
*/