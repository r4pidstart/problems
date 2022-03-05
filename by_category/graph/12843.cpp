// https://www.acmicpc.net/problem/12843
// 2022-03-06 02:26:01 204ms
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
    int n,m; scanf("%d%d", &n, &m);
    vector<int> type(n+1);
    for(int i=0; i<n; i++)
    {
        int a; char b; scanf("%d %c", &a, &b);
        type[a]= b=='c';
    }
    bipartite_matching bi(n+1, n+1);
    // vector<int> used(n+1, 0);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        if(type[a]) bi.add_edge(a,b);
        else bi.add_edge(b,a);
        // used[a]=1, used[b]=1;
    }
    printf("%d", n-bi.find_match());
}

/*
    같은 내용을 공유하는 과목들 중 하나만을 들어야 한다. -> a-b 간선에서 a나 b중 하나만을 골라야 한다. -> minimum vertex cover
    그런데, 최대한의 강의를 듣고 싶으므로, 선택된 정점을 제외한 모든 정점을 고르면 조건을 만족하는 가장 많은 강의의 갯수를 찾을 수 있다.
*/