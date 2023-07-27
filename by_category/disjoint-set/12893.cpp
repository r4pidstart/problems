// https://www.acmicpc.net/problem/12893
// 2023-07-28 01:29:12
#include"bits/stdc++.h"
using namespace std;

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

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    Dsu dsu(n+1);

    vector<vector<int> > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
    }

    for(int i=1; i<=n; i++)
    {
        for(auto it : graph[i])
            for(auto ne : graph[it])
                dsu.merge(i, ne);
    }
    for(int i=1; i<=n; i++)
        for(auto it : graph[i])
            if(dsu.find(it) == dsu.find(i)) return !printf("0");
            
    printf("1");
}

/*
    
*/