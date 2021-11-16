// https://www.acmicpc.net/problem/15903
// 2021-11-17 02:50:28 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    int n,m; scanf("%d%d", &n,&m);
    for(int i=0; i<n; i++)
    {
        int tmp; scanf("%d", &tmp);
        pq.push(tmp);
    }
    while(m--)
    {
        long long a=pq.top(); pq.pop();
        long long b=pq.top(); pq.pop();
        pq.push(a+b), pq.push(a+b);
    }

    long long ans=0;
    while(!pq.empty())
        ans+=pq.top(), pq.pop();
    printf("%lld", ans);
}

/*
    
*/