// https://www.acmicpc.net/problem/9370
// 2021-04-16 22:23:12 544ms
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 0x7FFFFFFF
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
    return dist[end]==INF ? 0 : dist[end];
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
            if((a==v1 && b==v2) || (a==v2 && b==v1))
            {
                dest[a].push_back({b,c*2-1});
                dest[b].push_back({a,c*2-1});
            }
            else
            {
            dest[a].push_back({b,c*2});
            dest[b].push_back({a,c*2});
            }
        }

        vector<int> possible_dest;
        for(int i=0; i<t; i++)
        {
            int tmp; scanf("%d", &tmp);
            if(dijkstra(start,tmp)%2==1)
                possible_dest.push_back(tmp);
        }

        sort(possible_dest.begin(), possible_dest.end());
        for(int result : possible_dest)
            printf("%d ", result);
        printf("\n");
    }
    return 0;
}