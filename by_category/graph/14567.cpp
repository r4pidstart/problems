// https://www.acmicpc.net/problem/14567
// 2023-12-24 03:57:13
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > graph(n+1);
    vector<int> indegree(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<pair<int, int> > q;
    for(int i=1; i<=n; i++)
        if(indegree[i]==0)
            q.push({i, 1});
    
    vector<int> ans(n+1);
    while(q.size())
    {
        auto [now, days]=q.front();
        q.pop();
        ans[now]=days;

        for(int next : graph[now])
        {
            indegree[next]--;
            if(indegree[next]==0)
                q.push({next, days+1});
        }
    }
    for(int i=0; i<n; i++)
        printf("%d ", ans[i+1]);
}

/*
    
*/