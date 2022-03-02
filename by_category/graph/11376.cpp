// https://www.acmicpc.net/problem/11376
// 2022-03-03 01:18:48 2364ms
#include<bits/stdc++.h>
using namespace std;

class bipartite_matching
{
    // O(VE)
    private:
        vector<vector<int> > graph;
        vector<int> btoa, visited;
        bool make_match(int now)
        {
            visited[now]=1;
            for(int next : graph[now])
                if(btoa[next] == -1 or (!visited[btoa[next]] and make_match(btoa[next])))
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
                fill(visited.begin(), visited.end(), 0);
                if(make_match(i)) match++;
            }
            return match;
        }
};

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    bipartite_matching bi(n*2+1, m+1);
    for(int i=1; i<=n; i++)
    {
        int a; scanf("%d", &a);
        while(a--)
        {
            int b; scanf("%d", &b);
            bi.add_edge((i<<1)-1, b);
            bi.add_edge((i<<1), b);
        }
    }
    printf("%d", bi.find_match());
}

/*
    
*/