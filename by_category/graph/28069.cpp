// https://www.acmicpc.net/problem/28069
// 2023-06-09 01:14:45
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    vector<int> visited(n+1);
    queue<pair<int,int> > q;
    visited[0]=1;
    q.push({0, 0});
    while(q.size())
    {
        auto [now, cnt]=q.front();
        q.pop();

        if(cnt==k) continue;
        if(now+now/2 < n+1 and !visited[now+now/2]) 
            q.push({now+now/2, cnt+1}), visited[now+now/2]=1;
        if(now+1 < n+1 and !visited[now+1])
            q.push({now+1, cnt+1}), visited[now+1]=1;
    }
    printf("%s", visited[n] ? "minigimbob":"water");
}

/*
    
*/