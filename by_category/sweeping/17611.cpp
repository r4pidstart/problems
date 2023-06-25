// https://www.acmicpc.net/problem/17611
// 2023-06-25 09:47:28
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);

    vector<vector<pair<int,int> > > line(2); // h, v
    pair<int,int> prev, first;
    
    scanf("%d%d", &prev.first, &prev.second);
    first=prev;
    for(int i=1; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        if(prev.first==a) // h
            line[0].push_back({prev.second, b});
        else // v
            line[1].push_back({prev.first, a});
        prev={a, b};
    }
    if(prev.first==first.first)
        line[0].push_back({prev.second, first.second});
    else
        line[1].push_back({prev.first, first.first});

    for(auto& it : line[0])
        if(it.first > it.second)
            swap(it.first, it.second);
    for(auto& it : line[1])
        if(it.first > it.second)
            swap(it.first, it.second);

    sort(line[0].begin(), line[0].end());
    sort(line[1].begin(), line[1].end());

    int ans=0;
    for(int i=0; i<2; i++)
    {
        priority_queue<int, vector<int>, greater<> > pq;
        for(auto it : line[i])
        {
            while(pq.size() and pq.top() <= it.first)
                pq.pop();
            pq.push(it.second);
            ans=max(ans, (int)pq.size());
        }
    }
    printf("%d", ans);
}

/*
    
*/