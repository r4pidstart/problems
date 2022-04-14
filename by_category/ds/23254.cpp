// https://www.acmicpc.net/problem/23254
// 2022-04-15 01:01:53 368ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<pair<int,int> > data(m);
    // vector<int> def(m), score_per_time(m);

    for(int i=0; i<m; i++)
        scanf("%d", &data[i].second);
    for(int i=0; i<m; i++)
        scanf("%d", &data[i].first);

    priority_queue<pair<int,int> > pq; 
    for(int i=0; i<m; i++)
    {
        if(data[i].first + data[i].second <= 100)
            pq.push({data[i].first, data[i].second});
        else
            pq.push({100 - data[i].second, data[i].second});
    }

    int total_score=0, remaining_time=n*24;
    while(remaining_time)
    {
        auto now=pq.top(); pq.pop();

        if(now.second+now.first + now.first > 100) pq.push({100 - (now.second+now.first), now.second+now.first});
        else pq.push({now.first, now.second+now.first});
        remaining_time--;
    }

    while(!pq.empty())
    {
        auto [ds, now]=pq.top(); pq.pop();
        total_score+=now;
    }

    printf("%d", total_score);
}

/*
    
*/