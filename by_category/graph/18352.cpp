// https://www.acmicpc.net/problem/18352
// 2022-02-02 00:35:19 548ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m,k,x; scanf("%d%d%d%d", &n,&m,&k,&x);
    vector<vector<int> > graph(n+1);

    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        graph[a].push_back(b);
    }

    // bfs
    queue<pair<int,int> > q;
    vector<int> dist(n+1, -1);
    q.push({x,0});
    int flag=0;
    while(!q.empty())
    {
        int now=q.front().first, cnt=q.front().second;
        q.pop();
        if(dist[now] != -1) continue;
        dist[now]=cnt;
        if(cnt == k) flag=1;

        for(int next : graph[now])
            q.push({next, cnt+1});
    }

    if(!flag) return !printf("-1");
    for(int city=0; city<=n; city++)
        if(dist[city] == k) printf("%d\n", city);
}

/*
    
*/