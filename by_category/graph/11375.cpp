// https://www.acmicpc.net/problem/11375
// 2022-03-03 01:08:07 540ms
#include<bits/stdc++.h>
using namespace std;

class bipartite_matching
{
    // O(VE)
    private:
        vector<vector<int> > graph;
        vector<int> groupA, groupB, visited;
        int make_match(int now)
        {
            visited[now]=1;

            for(int next : graph[now])
                if(groupB[next] == -1 or (!visited[groupB[next]] and make_match(groupB[next])))
                {
                    groupA[now]=next, groupB[next]=now;
                    return 1;
                }

            return 0;
        }
    public: 
        bipartite_matching(int sizeA, int sizeB)
        {
            graph.assign(sizeA, vector<int>());
            groupA.assign(sizeA, -1), groupB.assign(sizeB, -1);
            visited.assign(sizeA, 0);
        }
        void add_edge(int fromA, int toB)
        {
            graph[fromA].push_back(toB);
        }
        int find_match(void) 
        {
            int match=0;
            for(int i=0; i<groupA.size(); i++)
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
    bipartite_matching bi(n+1, m+1);
    for(int i=1; i<=n; i++)
    {
        int a; scanf("%d", &a);
        while(a--)
        {
            int b; scanf("%d", &b);
            bi.add_edge(i, b);
        }
    }
    printf("%d", bi.find_match());
}

/*
    
*/