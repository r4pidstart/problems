// https://www.acmicpc.net/problem/14464
// 2023-04-26 20:34:13
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    multiset<int> ms;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        ms.insert(a);
    }

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<> > pq2;
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        pq2.push({b,a});
    }

    int cnt=0;
    while(pq2.size())
    {
        auto [e,s]=pq2.top(); pq2.pop();
        auto it=ms.lower_bound(s);
        if(it!=ms.end() and *it <= e) cnt++, ms.erase(it);
    }
    printf("%d", cnt);
}

/*
    
*/