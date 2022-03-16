// https://www.acmicpc.net/problem/2644
// 2022-03-16 23:54:36 0ms
#include<bits/stdc++.h>
using namespace std;

vector<int> visited(101, 0);
vector<vector<int> > graph(101);

void dfs(int now, int target, int cnt)
{
    if(visited[now]) return;
    visited[now]++;

    if(now==target)
        exit(!printf("%d", cnt));
    for(auto next : graph[now])
        dfs(next, target, cnt+1);
}

int main(void)
{
    int n; scanf("%d", &n);
    int a,b; scanf("%d%d", &a, &b);
    int m; scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        int c,d; scanf("%d%d", &c, &d);
        graph[c].push_back(d);
        graph[d].push_back(c);
    }

    dfs(a, b, 0);
    printf("-1");
}

/*
    
*/