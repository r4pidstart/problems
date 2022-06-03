// https://www.acmicpc.net/problem/13905
// 2022-06-04 01:59:42
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    int s,e; scanf("%d%d", &s, &e);
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    priority_queue<pair<int,int> > pq;
    vector<int> visited(n+1);
    pq.push({INT32_MAX/2, s});
    while(pq.size())
    {
        int now=pq.top().second, lim=pq.top().first;
        pq.pop();
        if(lim < visited[now]) continue;
        else visited[now]=lim;

        for(auto next : graph[now])
        {
            if(!visited[next.first] or min(lim, next.second) > visited[next.first])
            {
                visited[next.first]=min(lim, next.second);
                pq.push({visited[next.first], next.first});
            }
        }
    }
    printf("%d", visited[e]);
}

/*
    
*/