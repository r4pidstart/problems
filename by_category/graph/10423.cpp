// https://www.acmicpc.net/problem/10423
// 2021-10-16 23:20:13 72ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m,k; scanf("%d%d%d", &n,&m,&k);
    vector<vector<pair<int,int> > > graph(n+1);
    vector<int> powered(n+1,0);
    
    for(int i=0; i<k; i++)
    {
        int a; scanf("%d", &a);
        powered[a]=1;
    }

    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({c,b});
        graph[b].push_back({c,a});
    }

    // prim algorithm

    // 발전소가 설치된 곳의 간선을 모두 우선순위 큐에 집어넣기
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for(int i=1; i<=n; i++)
        if(powered[i])
            for(auto& it : graph[i]) pq.push(it);

    int ans=0;
    while(!pq.empty())
    {
        auto now=pq.top();
        pq.pop();

        if(!powered[now.second])
        {
            powered[now.second]++;
            ans+=now.first;
            for(auto& it : graph[now.second]) pq.push(it);
        }
    }
    printf("%d", ans);
}

/*
    
*/