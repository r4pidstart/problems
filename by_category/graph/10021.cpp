// https://www.acmicpc.net/problem/10021
// 2024-04-20 16:22:44
#include"bits/stdc++.h"
using namespace std;

int get_dist(pair<int, int>& a, pair<int, int>& b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int main(void)
{
    int n,c; scanf("%d%d", &n, &c);
    vector<pair<int, int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    
    int ans=0;
    vector<int> used(n+1);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    pq.push({0, 0});

    while(pq.size())
    {
        auto [dist, now]=pq.top();
        pq.pop();

        if(used[now]) continue;
        ans+=dist;
        used[now]=1;

        for(int i=0; i<n; i++)
        {
            int next=i, next_dist=get_dist(arr[next], arr[now]);
            if(next_dist >= c and !used[next])
                pq.push({next_dist, next});
        }
    } 
    if(accumulate(used.begin(), used.end(), 0) != n)
        printf("-1");
    else
        printf("%d", ans);
}

/*
    
*/