// https://www.acmicpc.net/problem/16936
// 2023-06-18 09:51:05
#include"bits/stdc++.h"
using namespace std;

void dfs(int now, vector<vector<int> >& graph, vector<long>& arr)
{
    static vector<int> visited(graph.size());

    visited[now]=1;
    printf("%ld ", arr[now]);
    for(auto next : graph[now])
    {
        if(!visited[next])
        {
            dfs(next, graph, arr);
            return;
        }
    }
}
int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<long> arr(n);
    for(int i=0; i<n; i++)
        scanf("%ld", &arr[i]);
    
    vector<vector<int> > graph(n);
    vector<int> indegree(n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(arr[i]*2 == arr[j]) graph[i].push_back(j), indegree[j]++;
            else if(arr[i]%3==0 and arr[i]/3 == arr[j]) graph[i].push_back(j), indegree[j]++;

    int start=-1;
    for(int i=0; i<n; i++)
        if(indegree[i]==0)
        {
            assert(start==-1);
            start=i;
        }
    if(start==-1) start=0;

    dfs(start, graph, arr);
}

/*
    
*/