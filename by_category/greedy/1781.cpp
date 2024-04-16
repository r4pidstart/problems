// https://www.acmicpc.net/problem/1781
// 2024-04-15 19:29:40
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

            // if(parent[a]>parent[b]) swap(a,b);
            if(a>b) swap(a,b);
            
            parent[a]+=parent[b];
            parent[b]=a;
            return 0;
        }
};

int selection(int target, Dsu& dsu)
{
    if(target<1)
        return 0;
    
    int root=dsu.find(target);
    if(dsu.merge(target, root-1))
        return selection(root, dsu);
    return 1;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<pair<int, int> > arr(n);
    for(int i=0; i<n; i++)
        scanf("%d%d", &arr[i].second, &arr[i].first);
    
    sort(arr.begin(), arr.end(), greater<>());
    
    int ans=0;
    Dsu dsu(n+1);
    for(int i=0; i<n; i++)
    {
        auto [point, deadline]=arr[i];
        if(selection(deadline, dsu))
            ans+=point;
    }

    printf("%d", ans);

}

/*
    
*/