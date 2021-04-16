
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>
#define INF 0x7FFFFFFF
#define min(x,y) ((x)<(y) ? (x):(y))
using namespace std;

vector<pair<int,int> > dest[2001];
int route[2001]={};

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
                route[next]=now;
            }
        }
    }
    return 0;
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

        vector<int> possible_dest;
        for(int i=0; i<t; i++)
        {
            memset(route, 0, sizeof(int)*(n+1));
            int tmp; scanf("%d", &tmp);
            dijkstra(start,tmp);
            
            for(int it=tmp; it!=start; it=route[it])
            {
                if(route[it]==0)
                    break;
                if(it==v1 || it==v2)
                {
                    if((it==v1 && route[it]==v2) || (it==v2 && route[it]==v1))
                    // 경로에 v1-v2가 포함되어 있으면
                        possible_dest.push_back(tmp);
                    break;
                }
            }
        }

        sort(possible_dest.begin(), possible_dest.end());
        for(int result : possible_dest)
            printf("%d ", result);
        printf("\n");
    }
    return 0;
}