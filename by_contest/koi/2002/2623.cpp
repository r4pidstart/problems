// https://www.acmicpc.net/problem/2623
// 2022-04-03 02:47:53 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > graph(n+1);
    vector<int> indegree(n+1, 0);
    for(int i=0; i<m; i++)
    {
        int c; scanf("%d", &c);
        int prev; scanf("%d", &prev);
        while(--c)
        {
            int a; scanf("%d", &a);
            indegree[a]++;
            graph[prev].push_back(a);
            prev = a;
        }
    }

    // indegree가 0인 것 찾아서, 큐에 다 넣고 시작하기
    queue<int> q;
    vector<int> ans;
    for(int i=1; i<=n; i++)
        if(indegree[i]==0) q.push(i);
    while(q.size())
    {
        int now=q.front(); q.pop();
        ans.push_back(now);
        for(int next : graph[now])
        {
            indegree[next]--;
            if(!indegree[next])
                q.push(next);
        }
    }

    if(ans.size() != n) printf("0");
    else
        for(auto i : ans)
            printf("%d ", i);
}

/*
    
*/