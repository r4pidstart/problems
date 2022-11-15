// https://www.acmicpc.net/problem/16940
// 2022-11-16 01:42:44
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<set<int> > graph(n+1);
    // map<int, set<int> > m;

    for(int i=0; i<n-1; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].insert(b);
        graph[b].insert(a);
    }

    queue<int> q;
    queue<set<int> > q2;
    vector<int> visited(n+1);
    graph[0].insert(1);
    graph[1].insert(0);
    q.push(0);
    visited[0]=1;
    visited[1]=1;
    q2.push({1});

    while(q.size())
    {
        int now=q.front();
        set<int> cand=q2.front();
        q.pop(); q2.pop();

        while(!now or graph[now].size() - 1)
        {
            int input; scanf("%d", &input);
            if(graph[now].find(input) == graph[now].end() or cand.find(input) == cand.end())
                return !printf("0");
            else
            {
                set<int> se;
                for(auto next : graph[input])
                    if(!visited[next]) se.insert(next), visited[next]=1;
                q.push(input);
                q2.push(se);
                graph[now].erase(input);
            }

            if(!now) break;
        }
    }
    printf("1");
}

/*
    
*/