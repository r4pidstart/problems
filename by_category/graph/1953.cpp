// https://www.acmicpc.net/problem/1953
// 2023-03-04 19:54:02
#include"bits/stdc++.h"
using namespace std;

int dfs(int now, int t, vector<vector<int> >& graph, vector<int>& t1, vector<int>& t2, vector<int>& visited)
{
    visited[now]=1;
    
    if(t) t1.push_back(now);
    else t2.push_back(now);
    
    for(int next : graph[now])
        if(!visited[next])
            dfs(next, t^1, graph, t1, t2, visited);
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        while(a--)
        {
            int b; scanf("%d", &b);
            graph[i+1].push_back(b);
        }
    }
    vector<int> t1, t2, visited(n+1);
    for(int i=0; i<n; i++)
        if(!visited[i+1])
            dfs(i+1, 0, graph, t1, t2, visited);

    printf("%d\n", t1.size());
    sort(t1.begin(), t1.end());
    for(auto i : t1)
        printf("%d ", i);
        
    printf("\n%d\n", t2.size());
    sort(t2.begin(), t2.end());
    for(auto i : t2)
        printf("%d ", i);
}

/*
    
*/