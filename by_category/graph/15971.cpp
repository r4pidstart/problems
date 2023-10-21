// https://www.acmicpc.net/problem/15971    
// 2023-10-22 02:06:54
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,a,b; scanf("%d%d%d", &n, &a, &b);
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0; i<n-1; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    vector<int> visited(n+1);
    visited[a]=1;
    queue<tuple<int, int, int>> q;
    q.push({a, 0, 0});
    while(q.size())
    {
        auto [now, sum, max_len]=q.front();
        q.pop();

        if(now == b)
            return !printf("%d", sum-max_len);
        for(auto [next, ndist] : graph[now])
        {
            if(!visited[next])
                visited[next]=1, q.push({next, sum+ndist, max(max_len, ndist)});
        }
    }
}

/*
    
*/