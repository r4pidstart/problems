// https://www.acmicpc.net/problem/6497
// 2021-09-26 02:51:16 532ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int> > > graph;

int main(void)
{
    while(1)
    {
        int n,m; scanf("%d%d", &n,&m);
        if(n==0 && m==0) break;
        int usedE=0, tCost=0, tDist=0;
        graph.assign(n, vector<pair<int,int> >());
        for(int i=0; i<m; i++)
        {
            int a,b,cost; scanf("%d%d%d", &a, &b, &cost);
            tDist+=cost;
            graph[a].push_back({cost, b});
            graph[b].push_back({cost, a});
        }

        vector<int> visited(n,0);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        pq.push({0, 0});
        while(!pq.empty())
        {
            auto now=pq.top(); pq.pop();
            if(visited[now.second]) continue;
            visited[now.second]=1, tCost+=now.first, usedE++;
            for(auto &edge : graph[now.second])
                pq.push({edge.first, edge.second});
        }
        
        printf("%d\n", tDist-tCost);
    }
}

/*
    
*/