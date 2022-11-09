// https://www.acmicpc.net/problem/21924
// 2022-11-10 01:10:14
#include"bits/stdc++.h"
using namespace std;

class prim
{
    // graph[from]={to, cost}, O(ElogV)
    public:
        long long cost=0;
        prim(const vector<vector<pair<int, int> > >& graph)
        {
            if(graph.size()==1) return;
            int cnt=0;
            vector<int> visited(graph.size(), 0);
            priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;            
            pq.push({0,1});
            while(!pq.empty())
            {
                auto [now_cost, now]=pq.top(); pq.pop();
                if(visited[now]) continue;
                visited[now]=1, cnt++, cost+=now_cost;
                for(auto it : graph[now])
                    pq.push({it.second, it.first});
            }

            if(cnt != graph.size()-1) cost=-1;
        }
};

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<pair<int, int> > > arr(n+1);
    long total=0;
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        arr[a].push_back({b,c});
        arr[b].push_back({a,c});
        total+=c;
    } 

    // long ans=0;
    // priority_queue<pair<int,int>, vector<pair<int,int> >, greater<> > pq;
    // vector<int> connected(n+1);
    // pq.push({0, 1});

    // while(pq.size())
    // {
    //     int now=pq.top().second, dist=pq.top().first;
    //     pq.pop();
    //     if(connected[now]) continue;
    //     connected[now]=1, ans+=dist;
    //     for(auto next : arr[now])
    //         if(!connected[next.first])
    //             pq.push({next.second, next.first});
    // }

    // for(int i=1; i<=n; i++)
    //     if(!connected[i]) return !printf("-1");
    prim p(arr);
    printf("%ld", p.cost == -1 ? -1:total-p.cost);
}

/*
    
*/