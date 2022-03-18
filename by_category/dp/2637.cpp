// https://www.acmicpc.net/problem/2637
// 2022-03-19 07:50:03 0ms
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;

vector<int> base(101, 0);
vector<int> dfs(int now, int req_cnt, vector<vector<pair<int,int> > >& graph, vector<vector<int> >& dp)
{
    if(dp[now][0] != -1) return dp[now];
    vector<int> required(graph.size(), 0);
    if(graph[now].size()==0) 
    {
        base[now]=required[now]=1;
        return required;
    }

    for(auto next : graph[now])
    {
        auto tmp=dfs(next.first, next.second, graph, dp);
        for(int i=0; i<graph.size(); i++) required[i]+=tmp[i]*next.second;
    }
    
    return dp[now]=required;
}

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<pair<int,int> > > graph(n+1); // graph[i][j]={a,b} i번 부품을 만드는데 a번부품 b개 필요
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));  // dp[i] = i번 부품 만드는데 필요한 부품 갯수들
    for(int i=0; i<=n; i++) dp[i][0]=-1;
    vector<int> indegree(n+1);

    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b,c});
        indegree[b]++;
    }

    for(int i=1; i<=n; i++)
        if(!indegree[i])
            dfs(i, 1, graph, dp);
    
    for(int i=1; i<n; i++)
        if(base[i]) printf("%d %d\n", i, dp[n][i]);
}

/*
    
*/