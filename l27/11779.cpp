// https://www.acmicpc.net/problem/11779
// 2021-05-01 16:54:47 40ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<pair<int, int> > dest[n+1];
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        dest[a].push_back({b,c});
    }
    int start,end; scanf("%d%d", &start,&end);

    vector<int> cost(n+1, INT32_MAX/2);
    vector<int> route(n+1, 0);
    cost[start]=0;

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; 
    // dist, point
    pq.push({0, start});
    while(!pq.empty())
    {
        int now_dist=pq.top().first, now_point=pq.top().second;
        pq.pop();

        for(pair<int,int> next : dest[now_point])
        {
            int ndist=next.second, npoint=next.first;
            if(cost[npoint] > ndist+cost[now_point])
            {
                cost[npoint]=ndist+cost[now_point];
                pq.push({cost[npoint], npoint});
                route[npoint]=now_point;
            }
        }
    }
    
    stack<int> s;
    int pointer=end;
    while(route[pointer]!=0)
    {
        s.push(pointer);
        pointer=route[pointer];
    }
    s.push(start);
    printf("%d\n%ld\n", cost[end], s.size());
    while(!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
}