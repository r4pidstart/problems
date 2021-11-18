// https://www.acmicpc.net/problem/1325
// 2021-11-18 04:06:09 2580ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
vector<int> visited(10001);

int bfs(int i)
{
    queue<int> q;
    visited.assign(10001, 0);
    q.push(i);
    int ret=1;
    visited[i]=1;
    while(!q.empty())
    {
        int now=q.front(); q.pop();

        for(int& next : graph[now])
        {
            if(!visited[next])
            {
                visited[next]=1;
                ret++;
                q.push(next);
            }
        }
    }
    return ret;
}

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    graph.assign(n+1, {});
    vector<pair<int, int> > ans;
    
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        graph[b].push_back(a);
    }

    // bfs
    for(int i=1; i<=n; i++) ans.push_back({bfs(i), i});

    sort(ans.begin(), ans.end(), greater<pair<int,int> >());

    int prev=ans[0].first;
    stack<int> stk;
    for(int i=0; i<=n; i++)
        if(prev==ans[i].first) stk.push(ans[i].second);

    while(!stk.empty()) printf("%d ", stk.top()), stk.pop();   
}

/*
    
*/