// https://www.acmicpc.net/problem/14431
// 2023-11-18 01:47:47
#include"bits/stdc++.h"
using namespace std;

inline int get_dist(const pair<int, int>& a, const pair<int, int>& b)
{
    return (int)sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int main(void)
{
#ifdef LOCAL
#endif
    int ax,ay, bx,by; scanf("%d%d%d%d", &ax, &ay, &bx, &by);
    int n; scanf("%d", &n);
    vector<pair<int,int> > town(n);
    for(int i=0; i<n; i++)
        scanf("%d %d", &town[i].first, &town[i].second);
    town.emplace_back(ax, ay); // n
    town.emplace_back(bx, by); // n+1

    vector<int> prime_table(5000, 1);
    prime_table[0]=prime_table[1]=0;

    for(int i=2; i<5000; i++)
        for(int j=i*2; j<5000; j+=i)
            prime_table[j]=0;

    vector<vector<pair<int, int> > > graph(n+2);
    for(int i=0; i<n+2; i++)
        for(int j=i+1; j<n+2; j++)
        {
            if(prime_table[get_dist(town[i], town[j])])
                graph[i].push_back({j, get_dist(town[i], town[j])}),
                graph[j].push_back({i, get_dist(town[i], town[j])});
        }
    
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    pq.push({0, n});
    vector<int> dist(n+2, INT32_MAX/2);
    while(pq.size())
    {
        auto [nd, now]=pq.top();
        pq.pop();

        if(dist[now] < nd) continue;
        for(auto [next, ndist] : graph[now])
            if(dist[next] > nd+ndist)
            {
                dist[next]=nd+ndist;
                pq.push({dist[next], next});
            }
    }

    if(dist[n+1]==INT32_MAX/2)
        printf("-1");
    else
        printf("%d", dist[n+1]);
}

/*
    
*/