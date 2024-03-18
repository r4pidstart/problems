// https://www.acmicpc.net/problem/12892    
// 2024-03-18 21:36:31
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,d; scanf("%d%d", &n, &d);
    vector<pair<int, int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    
    sort(arr.begin(), arr.end());

    long ans=0, tmp=0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    for(int i=0; i<n; i++)
    {
        while(pq.size() and pq.top().first <= arr[i].first-d)
        {
            auto [p, v]=pq.top();
            pq.pop();
            tmp-=v;
        }

        pq.push(arr[i]);
        tmp+=arr[i].second;
        ans=max(ans, tmp);
    }
    printf("%ld", ans);
}

/*
    
*/