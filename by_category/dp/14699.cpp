// https://www.acmicpc.net/problem/14699
// 2024-06-16 00:50:02
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int solution(int now, const vector<int>& height, const vector<vector<int> >& graph)
{
    static vector<int> dp(height.size(), -1);
    if(dp[now] != -1)
        return dp[now];
    
    int ret=1;
    for(int next : graph[now])
    {
        if(height[now] < height[next])
            ret=max(ret, solution(next, height, graph)+1);
    }
    return dp[now]=ret;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,m; cin >> n >> m;
    vector<int> height(n+1);
    vector<vector<int> > graph(n+1);

    for(int i=0; i<n; i++)
        cin >> height[i+1];
    for(int i=0; i<m; i++)
    {
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
        cout << solution(i, height, graph) << '\n';
}

/*
    
*/