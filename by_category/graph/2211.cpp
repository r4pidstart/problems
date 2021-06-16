// https://www.acmicpc.net/problem/2211
// 2021-06-16 18:17:05 76ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<vector<pair<int,int> > > dest(n+1);
    for(int i=0; i<m; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        dest[a].push_back({b,c});
        dest[b].push_back({a,c});
    }

    // 다익스트라에서 경로 추적해서, 1번노드로부터 최단거리에 해당하는 모든 경로를 이어야함.
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    vector<int> res(n+1, INT32_MAX/2), prev(n+1, -1); 
    pq.push({0, 1}); // 1번 노드부터 시작
    res[1]=0;

    while(!pq.empty())
    {
        int now=pq.top().second, dist=pq.top().first;
        pq.pop();

        if(res[now] < dist)
            continue;
        
        for(auto &next : dest[now])
        {
            int ndist=dist+next.second;
            if(ndist < res[next.first])
            {
                res[next.first]=ndist;
                pq.push({ndist, next.first});
                prev[next.first]=now;
            }
        }
    }
    
    // 경로탐색 하나씩 하기
    set<pair<int,int> > edge; // 중복제거를 위해 오름차순으로 정렬해서 넣기
    for(int i=2; i<=n; i++)
    {
        int curr=i;
        while(prev[curr]!=-1)
        {
            if(prev[curr]<curr)
                edge.insert({prev[curr], curr});
            else
                edge.insert({curr, prev[curr]});
            curr=prev[curr];
        }
    }

    printf("%ld\n", edge.size());
    for(auto& e : edge)
        printf("%d %d\n", e.first, e.second);

}