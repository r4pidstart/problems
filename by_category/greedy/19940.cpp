// https://www.acmicpc.net/problem/19940
// 2023-04-22 04:33:58
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        queue<pair<int, tuple<int,int,int,int,int> > > q;
        int tmp=n<180 ? 0:n/60-3;
        n-=tmp*60;
        q.push({0, {tmp, 0, 0, 0, 0}});
        vector<int> visited(n+61);
        visited[0]=1;
        while(q.size())
        {
            auto [now, state]=q.front(); q.pop();
            auto& [a, b, c, d, e]=state;
            if(now==n)
            {
                printf("%d %d %d %d %d\n", a, b, c, d, e);
                break;
            }
            // mino
            if(now-1 >= 0 and !visited[now-1])
                visited[now-1]=1, q.push({now-1, {a, b, c, d, e+1}});
            // addo
            if(now+1 < n+61 and !visited[now+1])
                visited[now+1]=1, q.push({now+1, {a, b, c, d+1, e}});
            // mint
            if(now-10 >= 0 and !visited[now-10])
                visited[now-10]=1, q.push({now-10, {a, b, c+1, d, e}});
            // addt
            if(now+10 < n+61 and !visited[now+10])
                visited[now+10]=1, q.push({now+10, {a, b+1, c, d, e}});
            // addh
            if(now+60 < n+61 and !visited[now+60])
                visited[now+60]=1, q.push({now+60, {a+1, b, c, d, e}});
        }
    }
}

/*
    
*/