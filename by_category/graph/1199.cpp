// https://www.acmicpc.net/problem/1199
// 2021-11-03 05:43:24 832ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
vector<int> idx;

void dfs(int now)
{
    for(int& i=idx[now]; i<graph.size(); i++)
        if(graph[now][i])
            graph[now][i]--, graph[i][now]--, dfs(i);

    printf("%d ", now+1);
}

int main(void)
{
    int n; scanf("%d", &n);
    graph.assign(n, vector<int>(n,0));
    idx.assign(n,0);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &graph[i][j]);

    for(int i=0; i<n; i++) // indegree가 홀수면 안 된다.
        if(accumulate(graph[i].begin(), graph[i].end(), 0) & 1) return !printf("-1");
    dfs(0);
}
/*
    http://www.secmem.org/blog/2021/04/14/Euler-Circuit-and-Path/
*/