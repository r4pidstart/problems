// https://www.acmicpc.net/problem/24391
// 2022-01-29 23:23:04 48ms
#include<bits/stdc++.h>
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
    int n,m; scanf("%d%d", &n,&m);
    Dsu dsu(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        dsu.merge(a,b);
    }

    int ans=0, now;
    scanf("%d", &now);
    for(int i=1; i<n; i++)
    {
        int next; scanf("%d", &next);
        if(dsu.find(now) != dsu.find(next)) ans++;
        now=next;
    }
    printf("%d", ans);
}

/*
    
*/