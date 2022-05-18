// https://www.acmicpc.net/problem/16928
// 2022-05-19 02:51:58
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > graph(101);

    for(int i=0; i<n+m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
    }

    vector<int> dice(101);
    for(int i=1; i<101; i++)
        if(graph[i].size()==0)
        {
            for(int j=1; j<7 and i+j<101; j++)
                graph[i].push_back(i+j);
            dice[i]=1;
        }

    // bfs

    deque<pair<int,int> > q;
    q.push_back({1,0});
    vector<int> dist(101, -1);

    while(q.size())
    {
        int now=q.front().first, cnt=q.front().second; q.pop_front();

        if(dist[now] != -1) continue;
        else dist[now]=cnt;

        for(auto next : graph[now])
        {
            if(dice[now])
                q.push_back({next, cnt+1});
            else
                q.push_front({next, cnt});
        }
    }

    printf("%d", dist[100]);
}

/*
    
*/