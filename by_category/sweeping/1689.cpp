// https://www.acmicpc.net/problem/1689
// 2022-07-10 15:25:49 632ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    sort(arr.begin(), arr.end());

    priority_queue<int, vector<int>, greater<> > pq;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        pq.push(arr[i].second);
        while(pq.top() <= arr[i].first)
            pq.pop();
        ans=max(ans, (int)pq.size());
    }
    printf("%d", ans);
}

/*
    
*/