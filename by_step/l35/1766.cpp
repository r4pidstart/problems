// https://www.acmicpc.net/problem/1766
// 2021-06-05 14:57:09 40ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<vector<int> > graph(n+1);
    vector<int> in_degree(n+1,0);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        graph[a].push_back(b);
        in_degree[b]++;
    }

    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=1; i<=n; i++)
        if(in_degree[i]==0)
            pq.push(i);

    for(int i=0; i<n; i++)
    {
        if(pq.empty()==1)
            break;

        int now=pq.top();
        pq.pop();
        printf("%d ", now);

        for(int next : graph[now])
            if(--in_degree[next]==0)
                pq.push(next);
    }
}