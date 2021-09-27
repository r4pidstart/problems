// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;

int dfs(int now, int t)
{
    if(now==t) return 0;
    if(!graph[now].size()) return 1; // 리프 노드 

    int ret=0;
    for(int next : graph[now])
        if(next == t) ret+=graph[now].size()==1 ? 1:0;
        else ret+=dfs(next, t);
    return ret;
}

int main(void)
{
    int n; scanf("%d", &n);
    graph.assign(n, vector<int>());

    int root;
    for(int i=0; i<n; i++)
    {
        int p; scanf("%d", &p);
        if(p==-1) root=i;
        else graph[p].push_back(i);
    }

    int target; scanf("%d", &target);
    printf("%d", dfs(root, target));
}

/*
    
*/