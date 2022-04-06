// https://www.acmicpc.net/problem/1574
// 2022-03-14 01:15:32 12ms
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
    if(j == table[0].size()) return;
    slash[i][j]=line_cnt;
    numbering(i, j+1, 0, table, slash);
}

int r_line_cnt=0;
void r_numbering(int i, int j, int new_line, vector<vector<int> > &table, vector<vector<int> > &r_slash)
{
    if(new_line) r_line_cnt++;
    if(i == table.size()) return;
    r_slash[i][j]=r_line_cnt;
    r_numbering(i+1, j, 0, table, r_slash);
}

int main(void)
{
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<int> > table(n, vector<int>(m,0)), slash(n, vector<int>(m)), r_slash(n, vector<int>(m));

    int cnt=0; scanf("%d", &cnt);
    while(cnt--)
    {
        int a,b; scanf("%d%d", &a,&b);
        table[a-1][b-1]=1;
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(table[i][j]) continue;
            if(!slash[i][j]) numbering(i, j, 1, table, slash);
            if(!r_slash[i][j]) r_numbering(i, j, 1, table, r_slash);
        }
            

    bipartite_matching bi(line_cnt+1, r_line_cnt+1);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(table[i][j]) continue;
            bi.add_edge(slash[i][j], r_slash[i][j]);
        }

    printf("%d", bi.find_match());
}

/*
    
*/