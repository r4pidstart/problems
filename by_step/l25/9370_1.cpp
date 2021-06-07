// https://www.acmicpc.net/problem/9370
// 2021-04-16 22:23:12 2364ms
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 0x7FFFFFFF
#define min(x,y) ((x)<(y) ? (x):(y))
using namespace std;

vector<pair<int,int> > dest[2001];

int dijkstra(int start, int end)
{
    if(start==end)
        return 0;

    vector<int> dist(2001,INF);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    dist[start]=0;
    pq.push({start,0});
    while(!pq.empty())
    {
        int now=pq.top().first, total_dist=pq.top().second;
        pq.pop();

        if(dist[now]<total_dist)
            continue;
            
        for(auto it=dest[now].begin(); it!=dest[now].end(); it++)
        {
            int next=it->first, n_dist=it->second;
            if(dist[next]>total_dist+n_dist)
            {
                dist[next]=total_dist+n_dist;
                pq.push({next, dist[next]});
            }
        }
    }
    return dist[end]!=INF ? dist[end] : 100000000;
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,m,t; scanf("%d%d%d", &n,&m,&t);
        for(int i=1; i<=n; i++)
            dest[i]=vector<pair<int,int> >();
        int start, v1,v2; scanf("%d%d%d", &start, &v1,&v2);
        // v1-v2를 무조건 지남.

        for(int i=0; i<m; i++)
        {
            int a,b,c; scanf("%d%d%d", &a,&b,&c);
            dest[a].push_back({b,c});
            dest[b].push_back({a,c});
        }

        int v1_to_v2;
        for(auto it=dest[v1].begin(); it!=dest[v1].end(); it++)
        {
            if(it->first==v2)
            {
                v1_to_v2=it->second;
                break;
            }
        }

        vector<int> possible_dest;
        for(int i=0; i<t; i++)
        {
            int tmp; scanf("%d", &tmp);
            int target_dest=dijkstra(start,tmp),
                tmp_dest1=(dijkstra(start,v1)+v1_to_v2+dijkstra(v2,tmp)),
                tmp_dest2=(dijkstra(start,v2)+v1_to_v2+dijkstra(v1,tmp));

            int tmp_dest=min(tmp_dest1, tmp_dest2);
            // min(start - v1 - v2 - tmp, start - v2 - v1 - tmp)

            if(tmp_dest == target_dest)
            // 최단 거리와 같으면
                possible_dest.push_back(tmp);
        }

        sort(possible_dest.begin(), possible_dest.end());
        for(int result : possible_dest)
            printf("%d ", result);
        printf("\n");
    }
    return 0;
}