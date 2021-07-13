// https://www.acmicpc.net/problem/11779
// 2021-07-14 00:30:14 44ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, m; scanf("%d%d", &n,&m);
    vector<vector<pair<int, int> > > dest(n+1, vector<pair<int, int> >());
    vector<int> dist(n+1, INT32_MAX/2), route(n+1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        dest[a].push_back({b, c});
    }

    int start, end; scanf("%d%d", &start, &end);
    dist[start]=0;
    pq.push({0, start});

    while(!pq.empty())
    {
        int now_dist=pq.top().first, now=pq.top().second;
        pq.pop();

        if(dist[now] < now_dist) continue;

        for(auto next_p : dest[now])
        {
            int next=next_p.first, next_dist=next_p.second;
            if(dist[next] > now_dist + next_dist)
            {
                dist[next]=now_dist+next_dist;
                route[next]=now;
                pq.push({dist[next], next});
            }
        }
    }
    int cur=end;
    stack<int> ans;
    while(cur!=0)   
    {   
        ans.push(cur);
        cur=route[cur];
    }

    printf("%d\n%ld\n", dist[end], ans.size());
    while(!ans.empty())
    {
        printf("%d ", ans.top());
        ans.pop();
    }
}

/*

*/
