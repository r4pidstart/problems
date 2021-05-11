// https://www.acmicpc.net/problem/1197
// 2021-05-11 22:53:36 80ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int v,e; scanf("%d%d", &v,&e);
    vector<vector<pair<int,int> > > dest(v+1);
    vector<int> selected(v+1, 0);
    // dest[now]={weight, next}
    for(int i=0; i<e; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        dest[a].push_back({c,b});
        dest[b].push_back({c,a});
    }
    long long sum=0;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push({0,1}); // 1번 정점부터 시작
    while(!pq.empty())
    {
        if(selected[pq.top().second] == 0)
        {
            int next=pq.top().second;
            sum+=pq.top().first;
            selected[next]++;
            for(auto it=dest[next].begin(); it!=dest[next].end(); it++)
                pq.push(*it);
        }
        else
            pq.pop();
    }
    printf("%lld", sum);

}