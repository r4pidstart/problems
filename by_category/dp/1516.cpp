// https://www.acmicpc.net/problem/1516
// 2021-08-23 01:44:31 8ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > graph(n, vector<int>());
    vector<int> indegree(n), cost(n), ans(n);

    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &cost[i]);
        int b; scanf("%d", &b);
        while(b!=-1)
        {
            graph[b-1].push_back(i);
            indegree[i]++;
            scanf("%d", &b);
        }
    }

    queue<int> q;
    for(int i=0; i<n; i++)
        if(indegree[i]==0)
            q.push(i); 

    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        ans[now]+=cost[now];

        for(int& next : graph[now])
        {
            indegree[next]--;
            ans[next]=max(ans[next], ans[now]);
            if(!indegree[next]) 
                q.push(next);
        }
    }
    for(int& i : ans)
        printf("%d\n", i);
}

/*

*/