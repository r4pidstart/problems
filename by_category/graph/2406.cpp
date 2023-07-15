// https://www.acmicpc.net/problem/2406
// 2023-07-15 22:05:19
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
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        dsu.merge(a, b);
    }

    vector<tuple<int, int, int> > arr;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            int c; scanf("%d", &c);
            if(i<j) arr.push_back({c, i, j});
        }
            
    // get mst without 1st computer
    int ans=0;
    vector<pair<int,int> > res;
    sort(arr.begin(), arr.end());
    for(auto& [c, a, b] : arr)
    {
        if(a!=1 and b!=1 and dsu.find(a) != dsu.find(b))
            dsu.merge(a, b), ans+=c, res.push_back({a, b});
    }

    printf("%d %d\n", ans, res.size());
    for(auto& [a, b] : res)
        printf("%d %d\n", a, b);
}

/*
    
*/