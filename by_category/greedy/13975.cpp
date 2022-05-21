// https://www.acmicpc.net/problem/13975
// 2022-05-22 01:40:38 820ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        for(int i=0; i<n; i++)
        {
            int a; scanf("%d", &a);
            pq.push(a);
        }

        long long ans=0;
        while(pq.size() != 1)
        {
            long long a=pq.top(); pq.pop();
            long long b=pq.top(); pq.pop();
            pq.push(a+b);
            ans+=a+b;
        }
        printf("%lld\n", ans);
    }
}

/*
    
*/