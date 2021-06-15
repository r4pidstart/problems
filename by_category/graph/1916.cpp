// https://www.acmicpc.net/problem/1916
// 2021-06-15 19:00:14 36ms 
#include<bits/stdc++.h>
using namespace std;

const int INF = INT32_MAX/2;
vector<vector<pair<int,int> > > dest;
vector<int> res;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    dest.assign(n+1, vector<pair<int,int> >());
    res.assign(n+1, INF);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        dest[a].push_back({b,c});
    }

    int start, end; scanf("%d%d", &start,&end);

    // dijkstra
    priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; 
    // w, now
    pq.push({0, start}); 
    res[start]=0;
    while(!pq.empty())
    {
        int now=pq.top().second, w=pq.top().first;
        pq.pop();

        if(w > res[now]) 
            continue;
        for(auto& next : dest[now])
        {
            if(next.second+w < res[next.first])
            {
                res[next.first]=next.second+w;
                pq.push({next.second+w, next.first});
            }
        }
    }

    printf("%d", res[end]);
}