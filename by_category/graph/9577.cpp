// https://www.acmicpc.net/problem/9577
// 2022-03-26 08:04:40 0ms
#include<bits/stdc++.h>
using namespace std;

class bipartite_matching
{
    // O(VE)
    private:
        vector<vector<int> > graph;
        vector<int> btoa, visited;
        int visit_cnt;
        bool make_match(int now)
        {
            visited[now]=visit_cnt;
            for(int next : graph[now])
            {
                if(btoa[next] == now) continue;
                if(btoa[next] == -1 or (visited[btoa[next]] != visit_cnt and make_match(btoa[next])))
                {
                    btoa[next]=now;
                    return 1;
                }
            }
            return 0;
        }
    public: 
        bipartite_matching(int sizeA, int sizeB)
        {
            graph.assign(sizeA, vector<int>());
            btoa.assign(sizeB, -1);
            visited.assign(sizeA, 0);
        }
        inline void add_edge(int fromA, int toB)
        {
            graph[fromA].push_back(toB);
        }
        int find_match(void) 
        {
            int match=0;
            for(int i=0; i<graph.size(); i++)
            {
                visit_cnt++;
                if(make_match(i)) match++;
            }
            return match;
        }
        void rst(void)
        {
            btoa.assign(btoa.size(), -1);
            visited.assign(visited.size(), 0);
        }
};

int ans()
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > piece(101);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        vector<int> tmp(c);
        for(int i=0; i<c; i++) scanf("%d", &tmp[i]);
        for(int i=a; i<b; i++)
            for(auto j : tmp)
                piece[i].push_back(j);
    }

    bipartite_matching bi(101, 101);
    for(int i=0; i<=100; i++)
    {
        bi.rst();
        sort(piece[i].begin(), piece[i].end());
        piece[i].resize(unique(piece[i].begin(), piece[i].end()) - piece[i].begin());
        for(auto target : piece[i])
            bi.add_edge(target, i);
        
        if(bi.find_match() == n)
           return !printf("%d\n", i+1);
    }

    return !printf("-1\n");
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
        ans();
}

/*
    
*/