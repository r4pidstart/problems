// https://www.acmicpc.net/problem/
//
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
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<int> range(n);
        vector<pair<int,int> > arr(n);
        for(int i=0; i<n; i++)
            scanf("%d%d%d", &arr[i].first, &arr[i].second, &range[i]);

        Dsu dsu(n);
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                int xdist=(arr[i].first-arr[j].first)*(arr[i].first-arr[j].first);
                int ydist=(arr[i].second-arr[j].second)*(arr[i].second-arr[j].second);
                if(xdist+ydist <= (range[i]+range[j])*(range[i]+range[j]))
                    dsu.merge(i,j);
            }
        
        unordered_set<int> us;
        for(int i=0; i<n; i++)
            us.insert(dsu.find(i));
        printf("%d\n", us.size());
    }
}

/*
    
*/