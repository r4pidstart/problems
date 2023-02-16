// https://www.acmicpc.net/problem/17619
// 2023-02-17 01:43:14
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
    int n,q; scanf("%d%d", &n, &q);
    vector<tuple<int, int, int> > arr(n);
    Dsu dsu(n+1);
    for(int i=0; i<n; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        arr[i]={a,b,i+1};
    }
    sort(arr.begin(), arr.end());

    int prev_end=-1, prev_idx=-1;
    for(int i=0; i<n; i++)
    {
        auto& [s, e, idx]=arr[i];
        if(prev_end < s) // new set
            prev_end=e, prev_idx=idx;
        else
        {
            dsu.merge(prev_idx, idx);
            prev_end=max(prev_end, e);
        }
    }

    while(q--)
    {
        int a,b; scanf("%d%d", &a, &b);
        printf("%d\n", dsu.find(a)==dsu.find(b));
    }
}

/*
    
*/