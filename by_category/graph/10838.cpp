// https://www.acmicpc.net/problem/10838
// 2024-05-25 00:31:54
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int get_lca(int a, int b, const vector<int>& parent)
{
    static vector<int> visited(parent.size());
    static int cnt=0;
    cnt++;
    
    int cur=a;
    for(int i=0; i<1000 and cur!=-1; i++)
        visited[cur]=cnt, cur=parent[cur];
    cur=b;
    while(visited[cur]!=cnt)
        cur=parent[cur];
    
    return cur;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,k; cin >> n >> k;
    vector<int> parent(n), color(n), visited(n);
    parent[0]=-1;
    for(int i=1; i<n; i++)
        parent[i]=0;
    while(k--)
    {
        int r,a,b; cin >> r >> a >> b;
        if(r==1) // paint
        {
            int c; cin >> c;
            int lca=get_lca(a, b, parent);

            while(a != lca)
                color[a]=c, a=parent[a];
            while(b != lca)
                color[b]=c, b=parent[b];
        }
        else if(r==2) // move
        {
            parent[a]=b;
        }
        else // count
        {
            set<int> se;
            int lca=get_lca(a, b, parent);

            while(a != lca)
                se.insert(color[a]), a=parent[a];
            while(b != lca)
                se.insert(color[b]), b=parent[b];

            cout << se.size() << '\n';
        }
    }
}

/*
    
*/