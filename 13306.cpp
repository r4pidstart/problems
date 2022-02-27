// https://www.acmicpc.net/problem/13306
// 2022-02-27 23:06:24 144ms
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q; cin >> n >> q;
    Dsu uf(n+1);
    vector<int> parent(n+1);
    vector<int> removed_edge(n+1, 0);
    removed_edge.reserve(n);

    for(int i=2; i<=n; i++)
        cin >> parent[i];

    stack<query0> q0; stack<query1> q1;
    for(int i=0; i<n-1+q; i++)
    {
        int cmd; cin >> cmd;
        if(cmd==0)
        {  
            // cut edge
            int a; cin >> a;
            removed_edge[a]=1;
            q0.push({i, a});
        }
        else
        {
            // find route
            int a,b; cin >> a >> b;
            q1.push({i,a,b});
        }
    }

    for(int i=2; i<=n; i++)
    {
        if(!removed_edge[i]) // linked?
            uf.merge(i, parent[i]);
    }

    vector<int> ans;
    while(q0.size() || q1.size())
    {
        if(q0.empty())
        {
            // q1
            ans.push_back(uf.find(q1.top().a) == uf.find(q1.top().b));
            q1.pop();
        }
        else if(q1.empty())
        {
            // q0
            uf.merge(q0.top().a, parent[q0.top().a]);
            q0.pop();
        }
        else if(q0.top().idx < q1.top().idx)
        {
            // q1
            ans.push_back(uf.find(q1.top().a) == uf.find(q1.top().b));
            q1.pop();
        }
        else
        {
            // q0
            uf.merge(q0.top().a, parent[q0.top().a]);
            q0.pop();
        }
    }
    for(int i=ans.size()-1; i>=0; i--)
        cout << (ans[i] ? "YES":"NO") << "\n";
}

// /*
    
// */