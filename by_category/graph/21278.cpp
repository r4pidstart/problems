// https://www.acmicpc.net/problem/21278
// 2024-03-05 22:14:26
#include"bits/stdc++.h"
using namespace std;

int solution(int i, int j, const vector<vector<int> >& graph)
{
    vector<int> dist(graph.size(), INT32_MAX);
    queue<pair<int,int> > q;
    q.push({i, 0});
    q.push({j, 0});
    dist[i]=0, dist[j]=0;

    while(q.size())
    {
        auto [now, d]=q.front();
        q.pop();

        if(d > dist[now]) continue;

        for(int next : graph[now])
            if(dist[next]>d+1)
            dist[next]=d+1, q.push({next, d+1});
    }
    return accumulate(dist.begin()+1, dist.end(), 0);
}

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans=INT32_MAX, a=-1, b=-1;
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
        {
            if(solution(i, j, graph) < ans)
                ans=solution(i, j, graph), a=i, b=j;
        }
    printf("%d %d %d", a, b, ans*2);
}

/*
    
*/