// https://www.acmicpc.net/problem/14621
// 2022-01-20 03:42:49 4ms
#include<bits/stdc++.h>
using namespace std;

class kruskal
{
    // edge={cost, from, to}; O(ElogE+E)
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

            if(cnt != size-1) cost=-1;
        }
};

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<int> man(n);
    for(int i=0; i<n; i++)
    {
        char c; scanf(" %c", &c);
        if(c=='M') man[i]=1;
    }

    vector<pair<int, pair<int,int> > > edge;
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        if(man[a-1]!=man[b-1])
            edge.push_back({c,{a-1,b-1}});
    }
    if(edge.size() < n-1) return !printf("-1");
    kruskal mst(n, edge);
    printf("%d", mst.cost);
}

/*
    
*/