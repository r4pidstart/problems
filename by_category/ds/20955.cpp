// https://www.acmicpc.net/problem/20955
// 2023-06-07 02:23:00
#include"bits/stdc++.h"
using namespace std;

struct Dsu
{
    vector<int> parent;
    Dsu(int n)
    {
        parent=vector<int>(n, -1);
    }
    int merge(int a, int b)
    {
        a=find(a), b=find(b);
        if(a==b) return 1;
        parent[a]=b;
        return 0;
    }
    int find(int a)
    {
        if(parent[a]<0) return a;
        else return parent[a]=find(parent[a]);
    }
};

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    Dsu dsu(n+1);
    int unlink_cnt=0;
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        unlink_cnt+=dsu.merge(a, b);
        m=m;
    }
    int component_cnt=0;
    for(int i=1; i<=n; i++)
        if(dsu.parent[i]<0) component_cnt++;
    printf("%d", unlink_cnt+component_cnt-1);
}

/*
    
*/