// https://www.acmicpc.net/problem/24444
// 2022-05-12 02:00:24 128ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m,r; scanf("%d%d%d", &n, &m, &r);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(auto& it : graph)
        sort(it.begin(), it.end(), less<int>());

    queue<int> q;
    vector<int> visited(n+1);
    q.push(r);
    int cnt=0;
    while(q.size())
    {
        int now=q.front(); q.pop();

        if(visited[now]) continue;
        else visited[now]=++cnt;

        for(int next : graph[now])
            q.push(next);
    }
    
    for(int i=1; i<=n; i++)
        printf("%d\n", visited[i]);
}

/*
    
*/