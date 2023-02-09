// https://www.acmicpc.net/problem/14950
// 2023-02-10 02:31:44
#include"bits/stdc++.h"
using namespace std;

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
        long cost=0;
        vector<int> used_edge;
        kruskal(int size, vector<pair<int, pair<int,int> > >& edge, int t)
        {
            Dsu dsu(size);
            used_edge.assign(edge.size(),0);
            sort(edge.begin(), edge.end());
            int cnt=0;
            for(int i=0; i<edge.size(); i++)
                if(!dsu.merge(edge[i].second.first, edge[i].second.second))
                    cost+=edge[i].first+cnt*t, used_edge[i]=1, cnt++;

            // if(cnt != size-1) cost=-1;
        }
};

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,t; scanf("%d%d%d", &n, &m, &t);
    vector<pair<int, pair<int,int> > > graph(m);
    for(int i=0; i<m; i++)
        scanf("%d%d%d", &graph[i].second.first, &graph[i].second.second, &graph[i].first);
    kruskal mst(n+1, graph, t);
    printf("%ld", mst.cost);
}

/*
    
*/