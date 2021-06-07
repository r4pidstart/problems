// https://www.acmicpc.net/problem/2252
// 2021-06-04 12:21:33 40ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<vector<int> > graph(n+1);
    vector<int> edge_count(n+1,0);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        graph[a].push_back(b);
        edge_count[b]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++)
    {
        if(edge_count[i]==0) // 들어오는 간선이 없는 경우
            q.push(i);
    }

    vector<int> ans;
    for(int i=0; i<n; i++)
    {
        int now=q.front();
        ans.push_back(now);
        q.pop();
        for(int next : graph[now])
            if(--edge_count[next] == 0)
                q.push(next);
    }

    for(int i : ans)
        printf("%d ", i);
}