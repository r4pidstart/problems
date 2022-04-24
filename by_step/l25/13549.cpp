// https://www.acmicpc.net/problem/13549
// 2022-04-24 13:51:15 8ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    // bfs
    vector<int> visited(200000, 0);
    deque<pair<int,int > > q;
    q.push_back({n,0});
    int ans=INT32_MAX;
    while(!q.empty())
    {
        int now=q.front().first, cnt=q.front().second;
        q.pop_front();

        if(now == k)
            ans=min(ans, cnt);

        if(visited[now]) continue;
        visited[now]++;

        if(now+1 < 200000)
            q.push_back({now+1, cnt+1});
        if(now-1 > -1)
            q.push_back({now-1, cnt+1});
        if(now*2 < 200000)
            q.push_front({now*2, cnt});
    }
    printf("%d", ans);
}

/*
    
*/