// https://www.acmicpc.net/problem/17182
// 2023-10-09 00:42:16
#include"bits/stdc++.h"
using namespace std;

int solution(int now, vector<vector<int> >& graph)
{
    vector<vector<int> > dist(graph.size(), vector<int>((1<<graph.size())+1, INT32_MAX/2));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int> >, greater<> > pq;
    pq.push({0, now, 1<<now});
    dist[now][1<<now]=0;

    while(pq.size())
    {
        auto [now_cost, now, mask]=pq.top();
        pq.pop();

        if(dist[now][mask] < now_cost) continue;
        
        for(int i=0; i<graph.size(); i++)
        {
            int next_cost=graph[now][i], next_mask=mask|(1<<i);
            if(i!=now and now_cost+next_cost < dist[i][next_mask])
                pq.push({now_cost+next_cost, i, next_mask}), dist[i][next_mask]=now_cost+next_cost;
        }
    }    

    int ret=INT32_MAX;
    for(int i=0; i<graph.size(); i++)
        ret=min(ret, dist[i][(1<<graph.size())-1]);
    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    vector<vector<int> > graph(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &graph[i][j]);
    printf("%d", solution(k, graph));
}

/*
    
*/