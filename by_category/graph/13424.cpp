// https://www.acmicpc.net/problem/13424
// 2022-01-18 01:36:09 20ms
#include<bits/stdc++.h>
using namespace std;

class dijkstra
{
    // graph[from]={to, cost}, O(V^2+E)
    public:
        vector<int> dist;
        dijkstra(int start, const vector<vector<pair<int,int> > > &graph)
        {
            vector<int> visited(graph.size(), 0);
            dist.assign(graph.size(), INT32_MAX/2);
            dist[start]=0;
            
            while(true)
            {
                int now=-1, shortest=INT32_MAX;
                for(int i=0; i<graph.size(); i++)
                    if(shortest>dist[i] and !visited[i])
                        now=i, shortest=dist[i];
                if(now==-1) break;

                visited[now]=1;
                for(auto it : graph[now])
                {
                    if(visited[it.first]) continue;
                    dist[it.first]=min(dist[it.first], dist[now]+it.second);
                }
            }
        }
};

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m; scanf("%d%d", &n,&m);
        vector<vector<pair<int,int> > > graph(n+1);
        for(int i=0; i<m; i++)
        {
            int a,b,c; scanf("%d%d%d", &a,&b,&c);
            graph[a].push_back({b,c});
            graph[b].push_back({a,c});
        }

        int k; scanf("%d", &k);
        vector<int> dist_sum(n+1);
        for(int i=0; i<k; i++)
        {
            int s; scanf("%d", &s);
            dijkstra dijk(s, graph);
            for(int i=1; i<=n; i++)
                dist_sum[i]+=dijk.dist[i];
        }
        
        int ans=-1, anssum=INT32_MAX;
        for(int i=1; i<=n; i++)
            if(anssum > dist_sum[i])
                ans=i, anssum=dist_sum[i];
        printf("%d\n", ans);
    }
}

/*
    
*/