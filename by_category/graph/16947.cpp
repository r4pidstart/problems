// https://www.acmicpc.net/problem/16947
// 2022-11-01 01:03:09
#include"bits/stdc++.h"
using namespace std;

int find_cycle(int now, int prev, vector<int>& is_cycle, vector<vector<int> >& graph)
{
    static vector<int> visited(3001);

    if(visited[now])
    {
        is_cycle[now]=1;
        return now;
    }

    visited[now]=1;
    int tmp=0;
    for(auto next : graph[now])
    {
        if(next == prev) continue;
        tmp = find_cycle(next, now, is_cycle, graph);
        if(tmp)
        {
            if(tmp == now) tmp=0;
            is_cycle[now]=1;
            return now==tmp ? 0:tmp; 
        }
    }
    return 0;
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> is_cycle(n+1);
    find_cycle(1, 0, is_cycle, graph);

    for(int i=1; i<=n; i++)
    {
        vector<int> visited(n+1);
        queue<pair<int,int> > q;
        visited[i]=1;
        q.push({0, i});

        while(q.size())
        {
            int now=q.front().second, dist=q.front().first;
            q.pop();

            if(is_cycle[now])
            {
                printf("%d ", dist);
                break;
            }

            for(auto next : graph[now])
                if(!visited[next])
                    q.push({dist+1, next}), visited[next]=1;
        }
    }
    
}

/*
    
*/