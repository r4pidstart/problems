// https://www.acmicpc.net/problem/5014
// 2022-11-15 02:46:26
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int f,s,g,u,d; scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
    vector<int> visited(f+1);
    queue<pair<int,int> > q;
    q.push({0, s});
    visited[s]=1;
    
    while(q.size())
    {
        int now=q.front().second, cnt=q.front().first;
        q.pop();
        if(now == g) return !printf("%d", cnt);

        if(now + u <= f and !visited[now+u])
            visited[now+u]=1, q.push({cnt+1, now+u});
        if(now - d >= 1 and !visited[now-d])
            visited[now-d]=1, q.push({cnt+1, now-d});
    }
    printf("use the stairs");
}

/*
    
*/