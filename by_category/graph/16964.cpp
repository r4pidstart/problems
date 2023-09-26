// https://www.acmicpc.net/problem/16964
// 2023-09-25 20:32:37
#include"bits/stdc++.h"
using namespace std;

void check_dfs(int now, vector<set<int> >& graph, vector<int>& arr, int& idx)
{
    while(idx != arr.size() and graph[now].find(arr[idx]) != graph[now].end())
        check_dfs(arr[idx-1], graph, arr, ++idx);
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    vector<set<int> > graph(n+1);
    for(int i=0; i<n-1; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].insert(b);
        graph[b].insert(a);
    }

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int idx=0;
    graph[0].insert(1);
    check_dfs(0, graph, arr, idx);
    printf("%d", idx==n);
}

/*
    
*/