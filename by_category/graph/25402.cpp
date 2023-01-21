// https://www.acmicpc.net/problem/25402
// 2023-01-21 23:27:25
#include"bits/stdc++.h"
using namespace std;

class Dsu
{
    private:
    public:
        vector<int> parent;
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

void dfs(int now, int prev, vector<int>& parent, vector<vector<int> >& graph)
{
    for(auto next : graph[now])
    {
        if(next != prev)
        {
            parent[next]=now;
            dfs(next, now, parent, graph);
        }
    }
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<n-1; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> parent(n+1);
    vector<long> psum(n+1);
    for(int i=1; i<=n; i++)
        psum[i]=psum[i-1]+i-1;

    dfs(1, 0, parent, graph);

    int q; scanf("%d", &q);
    vector<int> included(n+1, -1);
    while(q--)
    {
        int k; scanf("%d", &k);
        Dsu dsu(k);
        vector<int> sets(k);
        for(int i=0; i<k; i++)
        {
            scanf("%d", &sets[i]);
            included[sets[i]]=i;
        }

        for(int i=0; i<sets.size(); i++)
        {
            if(included[parent[sets[i]]] != -1)
                dsu.merge(i, included[parent[sets[i]]]);
        }

        long ans=0;
        for(auto i : dsu.parent)
        {
            if(i < 0)
                ans+=psum[-i];
        }
        printf("%ld\n", ans);

        for(auto i : sets)
            included[i]=-1;
    }
}

/*
    
*/