// https://www.acmicpc.net/problem/16398
// 2022-01-20 04:04:31 248ms
#include<bits/stdc++.h>
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

            // if(cnt != graph.size()-1) cost=-1;
        }
};

class kruskal
{
    // edge={cost, {from, to}}, O(ElogE+E)
    private:
        class Dsu
        {
            private:
                vector<int> parent;
            public:
                Dsu(int size)
                {
                    parent.assign(size, -1);
                }
                int find(int i)
                {
                    if(parent[i]<0) return i;
                    else return parent[i]=find(parent[i]);
                }
                int merge(int a, int b)
                {
                    a=find(a), b=find(b);
                    if(a==b) return 1;

                    if(parent[a]>parent[b]) swap(a,b);
                    parent[a]+=parent[b];
                    parent[b]=a;
                    return 0;
                }
        };
    public:
        long long cost=0;
        vector<int> used_edge;
        kruskal(int size, vector<pair<int, pair<int,int> > >& edge)
        {
            Dsu dsu(size);
            used_edge.assign(edge.size(),0);
            sort(edge.begin(), edge.end());
            int cnt=0;
            for(int i=0; i<edge.size(); i++)
                if(!dsu.merge(edge[i].second.first, edge[i].second.second))
                    cost+=edge[i].first, used_edge[i]=1, cnt++;

            // if(cnt != size-1) cost=-1;
        }
};

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<pair<int, int> > > graph(n, vector<pair<int,int> >());
    vector<pair<int, pair<int, int> > > edge;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            int a; scanf("%d", &a);
            if(j<=i) continue;
            edge.push_back({a, {i,j}});
        }
    // prim mst(graph);
    kruskal mst(n, edge);
    printf("%lld", mst.cost);
}

/*
    
*/