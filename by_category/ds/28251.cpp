// https://www.acmicpc.net/problem/28251
// 2023-06-29 18:50:28
#include"bits/stdc++.h"
using namespace std;

struct Dsu
{
    vector<int> parent;
    Dsu(int s)
    {
        parent.assign(s, -1);
    }

    int find(int a)
    {
        if(parent[a]<0) return a;
        else return parent[a]=find(parent[a]);
    }

    int merge(int a, int b)
    {
        a=find(a), b=find(b);
        if(a==b) return 0;
        
        if(parent[a]<parent[b])
            swap(a, b);
        parent[a]+=parent[b];
        parent[b]=a;
        return 1;
    }
};

int main(void)
{
#ifdef LOCAL
#endif
    int n,q; scanf("%d%d", &n, &q);
    vector<long> sum(n+1), res(n+1);

    for(int i=1; i<=n; i++)
        scanf("%ld", &sum[i]);

    Dsu dsu(n+1);
    while(q--)
    {
        int a,b; scanf("%d%d", &a, &b);
        int prev_a=dsu.find(a), prev_b=dsu.find(b);
        if(dsu.merge(a, b))
        {
            a=dsu.find(a);
            res[a]=(sum[prev_a]*sum[prev_b])+res[prev_a]+res[prev_b];
            sum[a]=sum[prev_a]+sum[prev_b];
        }
        printf("%ld\n", res[dsu.find(a)]);
    }    
}

/*
    (2+3)*(4+5)
    -> 2*4 + 2*5 + 3*4 + 3*5 + 2*3 + 4*5
*/