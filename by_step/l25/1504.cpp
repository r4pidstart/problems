// https://www.acmicpc.net/problem/1504
// 2021-04-15 16:31:04 64ms
#include<iostream>
#include<queue>
#include<vector>
#define INF 0x7FFFFFFF
using namespace std;

vector<int> start_to(801, INF), v1_to(801, INF), v2_to(801, INF);
priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > diijstra;
vector <pair<int,int> > dest[801];

int main(void)
{
    int v,e; scanf("%d%d", &v,&e);
    for(int i=0; i<e; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        dest[a].push_back(make_pair(b,c));
        dest[b].push_back(make_pair(a,c));
    }
    int v1,v2; scanf("%d%d", &v1,&v2);

    start_to[1]=0, v1_to[v1]=0, v2_to[v2]=0;

    // start to
    diijstra.push(make_pair(0, 1));
    while(!diijstra.empty())
    {
        int now=diijstra.top().second, dist=diijstra.top().first;
        diijstra.pop();

        for(auto it=dest[now].begin(); it!=dest[now].end(); it++)
        {
            int ndist=it->second, next=it->first;
            if(start_to[next]>ndist+dist)
            {
                start_to[next]=ndist+dist;
                diijstra.push(make_pair(start_to[next], next));
            }
        }
    }

    // v1 to
    diijstra.push(make_pair(0, v1));
    while(!diijstra.empty())
    {
        int now=diijstra.top().second, dist=diijstra.top().first;
        diijstra.pop();

        for(auto it=dest[now].begin(); it!=dest[now].end(); it++)
        {
            int ndist=it->second, next=it->first;
            if(v1_to[next]>ndist+dist)
            {
                v1_to[next]=ndist+dist;
                diijstra.push(make_pair(v1_to[next], next));
            }
        }
    }

    // v2 to
    diijstra.push(make_pair(0, v2));
    while(!diijstra.empty())
    {
        int now=diijstra.top().second, dist=diijstra.top().first;
        diijstra.pop();

        for(auto it=dest[now].begin(); it!=dest[now].end(); it++)
        {
            int ndist=it->second, next=it->first;
            if(v2_to[next]>ndist+dist)
            {
                v2_to[next]=ndist+dist;
                diijstra.push(make_pair(v2_to[next], next));
            }
        }
    }

    // 1 to v1 to v2 to end
    int ans1=start_to[v1] + v1_to[v2] + v2_to[v];
    if(start_to[v1]!=INF && v1_to[v2]!=INF && v2_to[v]!=INF)
    {
        if(v1==1)
            ans1-=start_to[v1];
        if(v2==v)
            ans1-=v2_to[v];
    }
    else
        ans1=INF;

    // 1 to v2 to v1 to end
    int ans2=start_to[v2] + v2_to[v1] + v1_to[v];
    if(start_to[v2]!=INF && v2_to[v1]!=INF && v1_to[v]!=INF)
    {
        if(v2==1)
            ans2-=start_to[v2];
        if(v1==v)
            ans2-=v1_to[v];
    }
    else
        ans2=INF;

    int ans=min(ans1,ans2);

    printf("%d", ans==INF ? -1 : ans);
    return 0;
}