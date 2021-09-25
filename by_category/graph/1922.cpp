// https://www.acmicpc.net/problem/1922
// 2021-09-26 02:10:38 44ms
#include<bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int a)
{
    if(parent[a]<0) return a;
    return parent[a]=find(parent[a]);
}

int merge(int a, int b)
{
    a=find(a), b=find(b);
    if(a==b) return 1;
    if(a<b) swap(a,b);
    parent[a]+=parent[b];
    parent[b]=a;
    return 0;
}

struct edge
{
    int cost, x, y;
    bool operator<(edge& a) const
    { return cost<a.cost; }
};

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    // kruscal
    vector<edge> edges(m);
    parent.assign(n+1, -1);

    for(int i=0; i<m; i++)
        scanf("%d%d%d", &edges[i].x, &edges[i].y, &edges[i].cost);

    sort(edges.begin(), edges.end());

    int ans=0;
    for(auto& e : edges)
        if(merge(e.x, e.y)==0) ans+=e.cost;

    printf("%d", ans);
}

/*
    
*/