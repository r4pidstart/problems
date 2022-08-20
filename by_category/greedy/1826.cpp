// https://www.acmicpc.net/problem/1826
// 2022-08-21 05:48:24 4ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        arr[i]={a,b};
    }
    sort(arr.begin(), arr.end());

    int limit, dest, cnt=0, idx=0;
    scanf("%d%d", &dest, &limit);
    priority_queue<int> pq;

    while(dest > limit)
    {
        while(idx < n and arr[idx].first <= limit)
            pq.push(arr[idx++].second);
        if(!pq.size()) return !printf("-1");
        else cnt++, limit+=pq.top(), pq.pop();
    }
    printf("%d", cnt);
}

/*
    
*/