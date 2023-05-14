// https://www.acmicpc.net/problem/1800
// 2023-05-15 00:57:51
#include"bits/stdc++.h"
using namespace std;


int decision(int mid, vector<vector<pair<int,int> > >& graph, int k)
{
    vector<vector<int> > visited(graph.size(), vector<int>(k+1));
    queue<pair<int,int> > q;
    q.push({1, k});
    visited[1][k]=1;

    while(q.size())
    {
        auto [now, remain]=q.front();
        q.pop();

        if(now==graph.size()-1) return 1;

        for(auto [next, dist] : graph[now])
        {
            if(dist > mid)
            {
                if(remain and !visited[next][remain-1]) 
                    q.push({next, remain-1}), visited[next][remain-1]=1;
            }
            else if(!visited[next][remain])
                q.push({next, remain}), visited[next][remain]=1; 
        }
    }
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,p,k; scanf("%d%d%d", &n, &p, &k);
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0; i<p; i++)
    {
        int a,b,c; scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    int lo=0, hi=1000001, ans=1000001;
    while(lo<=hi)
    {
        int mid=lo+hi>>1;
        if(decision(mid, graph, k))
            ans=mid, hi=mid-1;
        else
            lo=mid+1;
    }
    if(ans==1000001) printf("-1");
    else printf("%d", ans);
}

/*
    
*/