// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int dfs(int now, int prev, int d, vector<vector<int> >& graph, vector<int>& siz)
{
    int dep=0, ret=0;
    for(auto next : graph[now])
        if(next != prev)
        {
            ret+=dfs(next, now, d, graph, siz);
            dep=max(dep, siz[next]+1);
        }
    siz[now]=dep;
    if(siz[now] >= d) ret+=2;
    return ret;
}

int main(void)
{
    int n,s,d; scanf("%d%d%d", &n, &s, &d);
    vector<vector<int> > graph(n+1);
    vector<int> siz(n+1);
    for(int i=0; i<n-1; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    printf("%d", max(0, dfs(s, -1, d, graph, siz)-2));
}

/*
    
*/