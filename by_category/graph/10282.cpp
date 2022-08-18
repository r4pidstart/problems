// https://www.acmicpc.net/problem/10282
// 2022-08-19 04:58:24 168ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,d,c; scanf("%d%d%d", &n, &d, &c);
        vector<vector<pair<int, int> > > graph(n+1);
        while(d--)
        {
            int a,b,c; scanf("%d%d%d", &a, &b, &c);
            graph[b].push_back({a, c});
        }
        vector<int> infected(n+1, -1);
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<> > pq;
        pq.push({0, c});
        infected[c]=0;

        while(pq.size())
        {
            int now=pq.top().second, time=pq.top().first;
            pq.pop();
            for(auto it : graph[now])
                if(infected[it.first]==-1 or infected[it.first] > time+it.second)
                    pq.push({time+it.second, it.first}), infected[it.first]=time+it.second;
        }
        printf("%d %d\n", count_if(infected.begin(), infected.end(), [&](int it){return it!=-1;}), *max_element(infected.begin(), infected.end()));
    }
}

/*
    
*/