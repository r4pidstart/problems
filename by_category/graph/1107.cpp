// https://www.acmicpc.net/problem/1107
// 2022-07-07 23:14:07 28ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<int> broken(10);
    for(int i=0; i<m; i++)
    {
        int a; scanf("%d", &a);
        broken[a]++;
    }

    int ans=abs(100 - n);
    queue<pair<int,int> > q;
    vector<int> visited(1000001);

    for(int i=0; i<10; i++)
        if(!broken[i])
            visited[i]++, q.push({i, 1});

    while(q.size())
    {
        int now=q.front().first, cnt=q.front().second; q.pop();
        ans=min(abs(now-n) + cnt, ans);

        for(int i=0; i<10; i++)
            if(!broken[i] and now*10+i<1000000 and !visited[now*10+i])
                visited[now*10+i]++, q.push({now*10+i, cnt+1});
    }    
    printf("%d", ans);
}

/*
    
*/