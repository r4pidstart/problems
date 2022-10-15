// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m,r; scanf("%d%d%d", &n, &m, &r);
    vector<vector<pair<int,int> > > graph(n+1);
    vector<int> arr(n+1);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i+1]);
    
    for(int i=0; i<r; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<> > pq;
        vector<int> dist(n+1, INT32_MAX/2);
        dist[i]=0;
        pq.push({0, i});

        while(pq.size())
        {
            int now=pq.top().second, ndist=pq.top().first;
            pq.pop();

            if(dist[now] < ndist) continue;

            for(auto next : graph[now])
                if(ndist + next.second < dist[next.first])
                {
                    dist[next.first]=ndist+next.second;
                    pq.push({dist[next.first], next.first});
                }
        }
        int tmp=0;
        for(int i=1; i<=n; i++)
            if(dist[i] <= m) tmp+=arr[i];
        ans=max(ans, tmp);
    }
    printf("%d", ans);
}

/*
    
*/