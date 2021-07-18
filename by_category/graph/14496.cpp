// https://www.acmicpc.net/problem/14496
// 2022-07-17 23:45:40
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int a,b; scanf("%d%d", &a, &b);
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int q,w; scanf("%d%d", &q, &w);
        graph[q].push_back(w);
        graph[w].push_back(q);
   }

    vector<int> visited(n+1);
    queue<pair<int,int> > q;
    q.push({a,0});
    visited[a]=1;
    while(q.size())
    {
        int now=q.front().first, cnt=q.front().second;
        q.pop();

        if(now == b)
            return !printf("%d", cnt);
        
        for(auto next : graph[now])
            if(!visited[next])
                visited[next]=1, q.push({next, cnt+1});
    }
    printf("-1");
}

/*
    
*/