// https://www.acmicpc.net/problem/12851
// 2022-09-10 00:52:42 56ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    vector<int> visited(200000, 0);
    queue<pair<int,int> > q;
    int cnt=0, time=INT32_MAX;
        q.push({n, 0});

    while(q.size())
    {
        int now=q.front().first, nowt=q.front().second;
        q.pop();

        visited[now]=1;

        if(now == k)
        {
            if(time==INT32_MAX)
                time=nowt;
            if(time==nowt)
                cnt++;
        }

        if(now+1 < 200000 and !visited[now+1])
            q.push({now+1, nowt+1});
        if(now-1 >= 0 and !visited[now-1])
            q.push({now-1, nowt+1});
        if(now*2 < 200000 and !visited[now*2])
            q.push({now*2, nowt+1});
    }
    printf("%d\n%d", time, cnt);
}

/*
    
*/