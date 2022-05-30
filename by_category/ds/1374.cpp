// https://www.acmicpc.net/problem/1374
// 2022-05-31 02:38:41 72ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int,int> > arr;
    for(int i=0; i<n; i++)
    {
        int t,a,b; scanf("%d%d%d", &t, &a, &b);
        arr.push_back({a,b});
    }

    sort(arr.begin(), arr.end());

    int ans=0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(auto it : arr)
    {
        while(pq.size() and pq.top() <= it.first)
            pq.pop();
        pq.push(it.second);
        ans=max(ans, (int)pq.size());
    }
    printf("%d", ans);
}

/*
    
*/