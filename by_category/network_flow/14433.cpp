// https://www.acmicpc.net/problem/14433
// 2022-03-25 08:09:33 0ms
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

int main(void)
{
    int n,m,k1,k2;
    scanf("%d%d%d%d", &n, &m, &k1, &k2);
    bipartite_matching bi1(n+1, m+1);
    bipartite_matching bi2(n+1, m+1);
    for(int i=0; i<k1; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        bi1.add_edge(a, b);
    }
    for(int i=0; i<k2; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        bi2.add_edge(a, b);
    }
    printf("%s", bi1.find_match() < bi2.find_match() ? "네 다음 힐딱이":"그만 알아보자");
}

/*
    
*/