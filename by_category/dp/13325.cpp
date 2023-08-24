// https://www.acmicpc.net/problem/13325
// 2023-08-25 00:17:19
#include"bits/stdc++.h"
using namespace std;

pair<long, long> solution(int now, int n, int dep, vector<vector<pair<int,int> > >& graph)
{
    if(!graph[now].size())
        return {0, 0};
    
    assert(graph[now].size() == 2);
    auto le=solution(graph[now][0].first, n, dep+1, graph);
    auto ri=solution(graph[now][1].first, n, dep+1, graph);

    int dif=abs((le.first+graph[now][0].second)-(ri.first+graph[now][1].second));
#ifdef LOCAL
    // printf("%d %f\n", abs(le-ri), pow(2, n-dep));
#endif
    return {max(le.first+graph[now][0].second, ri.first+graph[now][1].second), 
            le.second+ri.second+graph[now][0].second+graph[now][1].second+dif};
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    
    vector<vector<pair<int, int> > > graph(1<<(n+1));
    for(int i=1; i<(1<<n); i++)
    {
        int c; scanf("%d", &c);
        graph[i].push_back({i*2, c});
        scanf("%d", &c);
        graph[i].push_back({i*2+1, c});
    }

    printf("%ld", solution(1, n, 1, graph).second);
}

/*
    
*/