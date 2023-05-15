// https://www.acmicpc.net/problem/27440
// 2023-05-15 21:45:22
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    long ans=0; scanf("%ld", &ans);
    
    map<long, int> ma;
    queue<pair<long, int> > q;
    q.push({ans, 0});
    ma[0]=1;
    while(q.size())
    {
        auto [now, cnt]=q.front();
        q.pop();

        if(now==1) return !printf("%d", cnt);

        if(now%3==0 and ma[now/3] == 0)
            q.push({now/3, cnt+1}), ma[now/3]=1;
        if(now%2==0 and ma[now/2] == 0)
            q.push({now/2, cnt+1}), ma[now/2]=1;
        if(now-1>0 and ma[now-1] == 0)
            q.push({now-1, cnt+1}), ma[now-1]=1;
    }
}

/*
    
*/