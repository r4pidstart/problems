// https://www.acmicpc.net/problem/
// 2021-11-14 02:46:20 D
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    unsigned long long status=0;
    for(int i=0; i<n*n; i++)
    {
        int tmp; scanf("%d", &tmp);
        if(tmp) status|=(1LL<<i);
    }

    queue<pair<int, unsigned long long> > q;
    unordered_set<unsigned long long> uds;
    uds.reserve(1<<17);
    q.push({0,status});

    int ans=INT32_MAX;
    while(!q.empty())
    {
        auto now=q.front(); q.pop();
        if(uds.find(now.second) != uds.end()) continue;
        uds.insert(now.second);
        
        ans=min({ans, __builtin_popcountll(now.second)+now.first, n*n-__builtin_popcountll(now.second)+now.first});
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                now.second^=(1LL<<i+n*j);
                q.push({now.first+1, now.second});
            for(int j=0; j<n; j++)
                now.second^=(1LL<<i+n*j);

            for(int j=0; j<n; j++)
                now.second^=(1LL<<i*n+j);
                q.push({now.first+1, now.second});
            for(int j=0; j<n; j++)
                now.second^=(1LL<<i*n+j);
        }
    }
    printf("%d", ans);
}

/*
    
*/