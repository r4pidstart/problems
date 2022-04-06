// https://www.acmicpc.net/problem/2570
// 2022-03-14 01:07:01 0ms
#include<bits/stdc++.h>
using namespace std;

class bipartite_matching
{
    // O(VE)
    private:
        vector<vector<int> > graph;
        vector<int> btoa, visited;
        int visit_cnt=0;
        bool make_match(int now)
        {
            visited[now]=visit_cnt;
            for(int next : graph[now])
                if(btoa[next] == -1 or (visited[btoa[next]] != visit_cnt and make_match(btoa[next])))
                {
                    btoa[next]=now;
                    return 1;
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
};

int line_cnt=0;
void numbering(int i, int j, int new_line, vector<vector<int> > &table, vector<vector<int> > &slash)
{
    if(new_line) line_cnt++;
    if(i == table.size() or j == table.size() or table[i][j]) return;
    slash[i][j]=line_cnt;
    numbering(i+1, j+1, 0, table, slash);
}

int r_line_cnt=0;
void r_numbering(int i, int j, int new_line, vector<vector<int> > &table, vector<vector<int> > &r_slash)
{
    if(new_line) r_line_cnt++;
    if(i == table.size() or j < 0 or table[i][j]) return;
    r_slash[i][j]=r_line_cnt;
    r_numbering(i+1, j-1, 0, table, r_slash);
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > table(n, vector<int>(n)), slash(n, vector<int>(n)), r_slash(n, vector<int>(n));

    int m, cnt=0;; scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        table[a-1][b-1]=1, cnt++;
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(!slash[i][j]) numbering(i, j, 1, table, slash);
            if(!r_slash[i][j]) r_numbering(i, j, 1, table, r_slash);
        }
            

    bipartite_matching bi(line_cnt+1, r_line_cnt+1);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(table[i][j]) continue;
            bi.add_edge(slash[i][j], r_slash[i][j]);
        }

    printf("%d", bi.find_match());
}

/*
    
*/