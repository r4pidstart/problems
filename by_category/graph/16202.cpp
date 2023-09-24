// https://www.acmicpc.net/problem/16202
// 2023-09-24 14:48:49
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    vector<map<int,int> > graph(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a][b]=i+1;
        graph[b][a]=i+1;
    }

    for(int i=0; i<k; i++)
    {
        tuple<int, int, int> minimum_cost={INT32_MAX, 0, 0};
        vector<int> used(n+1);
        int vertex_count=0, sum=0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<> > pq;
        pq.push({12345, 1, 1});
        
        while(pq.size())
        {
            auto [c, prev, now]=pq.top();
            pq.pop();

            if(used[now]) continue;
            used[now]=1;
            vertex_count++;
            sum+=c;
            minimum_cost=min(minimum_cost, {c, prev, now}); 

            for(auto [next, ncost] : graph[now])
            {
                if(!used[next])
                    pq.push({ncost, now, next});
            }
        }

        if(vertex_count==n)
        {
            printf("%d ", sum-12345);
            auto [c, a, b]=minimum_cost;
            graph[a].erase(b);
            graph[b].erase(a);
        }
        else printf("0 ");
    }
}

/*
    
*/