// https://www.acmicpc.net/problem/2414
// 2022-03-27 06:09:30 0ms
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

int cnt_x=0;
void indexing_x(int x, int y, vector<vector<int> >& table, vector<vector<int> >& idx)
{
    if(idx[x][y]) return;
    idx[x][y]=++cnt_x;
    for(int i=x+1; i<table.size(); i++)
        if(table[i][y] == '*') idx[i][y]=cnt_x;
        else break;
}

int cnt_y=0;
void indexing_y(int x, int y, vector<vector<int> >& table, vector<vector<int> >& idx)
{
    if(idx[x][y]) return;
    idx[x][y]=++cnt_y;
    for(int i=y+1; i<table[0].size(); i++)
    {
        if(table[x][i] == '*') idx[x][i]=cnt_y;
        else break;
    }
}

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > table(n, vector<int>(m));
    vector<vector<int> > idx_x(n, vector<int>(m));
    vector<vector<int> > idx_y(n, vector<int>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &table[i][j]);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(table[i][j] == '*')
            {
                indexing_x(i, j, table, idx_x);
                indexing_y(i, j, table, idx_y);
            }
        }

    bipartite_matching bi(cnt_x+1, cnt_y+1);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(table[i][j] == '*')
                bi.add_edge(idx_x[i][j], idx_y[i][j]);
    printf("%d", bi.find_match());
}

/*
    
*/