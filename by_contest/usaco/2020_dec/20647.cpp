// https://www.acmicpc.net/problem/20647
// 2021-10-07 05:02:40 56ms
#include<bits/stdc++.h>
using namespace std;

vector<int> farm;
vector<vector<int> > graph;

int main(void)
{
    int n, ans=0; scanf("%d", &n);
    graph.assign(n+1, vector<int>());
    farm.assign(n+1, 0);
    for(int i=0; i<n-1; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    farm[1]=1;
    while(!q.empty())
    {
        // check next farms
        int require=1, now=q.front(), cows=1;
        q.pop();
        for(int& next : graph[now])
            if(!farm[next]) 
            {
                require++, ans++, farm[next]++; // move
                q.push(next);
            }
                
        while(require > cows) cows*=2, ans++; // superspreader
    }
    printf("%d", ans);
}

/*
    
*/