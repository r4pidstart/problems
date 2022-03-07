// https://www.acmicpc.net/problem/2191
// 2022-03-07 22:10:26 0ms
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

double get_dist(const pair<double, double>& mouse, pair<double, double>& hole)
{
    return (mouse.first-hole.first)*(mouse.first-hole.first) + (mouse.second-hole.second)*(mouse.second-hole.second);
}
int main(void)
{
    int n,m,s,v; scanf("%d%d%d%d", &n, &m, &s, &v);
    bipartite_matching bi(n+1, m+1);

    vector<pair<double, double> > mouse(n), hole(m);
    for(int i=0; i<n; i++)
        scanf("%lf%lf", &mouse[i].first, &mouse[i].second);
    for(int i=0; i<m; i++)
        scanf("%lf%lf", &hole[i].first, &hole[i].second);

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(get_dist(mouse[i], hole[j]) <= (double)s*s*v*v)
                bi.add_edge(i, j);

    printf("%d", n-bi.find_match());
}

/*
    결국 각 쥐마다 배정받을 수 있는 터널의 최대 개수를 구하는 것.
*/