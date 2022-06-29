// https://www.acmicpc.net/problem/13334
// 2022-06-29 14:57:13 56ms
#include"bits/stdc++.h"
using namespace std;

bool custom_sort(const pair<int,int>& a, const pair<int,int>& b)
{
    // 끝지점 기준으로 정렬
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int, int> > arr(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &arr[i].first, &arr[i].second);
        if(arr[i].first > arr[i].second) 
            swap(arr[i].first, arr[i].second);
    }
    sort(arr.begin(), arr.end(), custom_sort);

    int d; scanf("%d", &d);
    // sweeping
    int ans=0;
    priority_queue<int, vector<int>, greater<> > pq;
    
    for(int i=0; i<n; i++)
    {
        int end=arr[i].second;
        pq.push(arr[i].first);
        while(pq.size() and pq.top() < end - d)
            pq.pop();
        ans=max(ans, (int)pq.size());
    }   
    printf("%d", ans);
}

/*
    
*/