// https://www.acmicpc.net/problem/1326
// 2022-06-11 01:55:38 4ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n+1);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i+1]);
    
    int a,b; scanf("%d%d", &a, &b);
    queue<pair<int, int> > q;
    q.push({a,0});
    vector<int> visited(n+1);

    while(q.size())
    {
        int now=q.front().first, cnt=q.front().second; q.pop();

        if(visited[now]) continue;
        else visited[now]++;

        if(now == b)
            return !printf("%d", cnt);
        int next=now;
        while(true)
        {
            next+=arr[now];
            if(next > n) break;
            if(!visited[next])
                q.push({next, cnt+1});
        }

        next=now;
        while(true)
        {
            next-=arr[now];
            if(next < 1) break;
            if(!visited[next])
                q.push({next, cnt+1});
        }
    }
    printf("-1");
}

/*
    
*/