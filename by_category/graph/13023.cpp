// https://www.acmicpc.net/problem/13023
// 2022-02-12 23:40:41 40ms
#include<bits/stdc++.h>
using namespace std;

int find(int now, vector<vector<int> > &graph)
{
    static vector<int> visited(2000, 0);
    static int cnt=0;
    if(visited[now]) return 0; 
    
    cnt++;
    if(cnt == 5) return 1;
    visited[now]=1;
    for(auto next : graph[now])
        if(find(next, graph))
            return 1;
    visited[now]=0;
    cnt--;
    return 0;
}

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<vector<int> > graph(n);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }   

    for(int i=0; i<n; i++)
        if(find(i, graph))
            return !printf("1");
    printf("0");
}

/*
    
*/