// https://www.acmicpc.net/problem/13306
// 2022-02-27 23:06:24 252ms
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

struct query0
{
    int idx, a;
};

struct query1
{
    int idx, a,b;
};

int main(void)
{
    int n,q; scanf("%d%d", &n, &q);
    Dsu uf(n+1);
    vector<int> parent(n+1);
    unordered_set<int> removed_edge;
    removed_edge.reserve(n);

    for(int i=2; i<=n; i++)
        scanf("%d", &parent[i]);

    list<query0> q0; list<query1> q1;
    for(int i=0; i<n-1+q; i++)
    {
        int cmd; scanf("%d", &cmd);
        if(cmd==0)
        {  
            // cut edge
            int a; scanf("%d", &a);
            removed_edge.insert(a);
            q0.push_back({i, a});
        }
        else
        {
            // find route
            int a,b; scanf("%d%d", &a, &b);
            q1.push_back({i,a,b});
        }
    }

    for(int i=2; i<=n; i++)
    {
        if(removed_edge.find(i) == removed_edge.end()) // linked?
            uf.merge(i, parent[i]);
    }

    vector<int> ans;
    while(q0.size() || q1.size())
    {
        if(q0.empty())
        {
            // q1
            ans.push_back(uf.find(q1.back().a) == uf.find(q1.back().b));
            q1.pop_back();
        }
        else if(q1.empty())
        {
            // q0
            uf.merge(q0.back().a, parent[q0.back().a]);
            q0.pop_back();
        }
        else if(q0.back().idx < q1.back().idx)
        {
            // q1
            ans.push_back(uf.find(q1.back().a) == uf.find(q1.back().b));
            q1.pop_back();
        }
        else
        {
            // q0
            uf.merge(q0.back().a, parent[q0.back().a]);
            q0.pop_back();
        }
    }
    for(int i=ans.size()-1; i>=0; i--)
        printf("%s\n", ans[i] ? "YES":"NO");
}

// /*
    
// */