// https://www.acmicpc.net/problem/23844
// 2021-12-26 14:04:55 4ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
vector<int> floor_cnt;

void find_floor(int now, int prev, int now_floor)
{
    if(now_floor==floor_cnt.size())
        floor_cnt.push_back(0);
    
    floor_cnt[now_floor]++;

    for(auto& next : graph[now])
        if(next!=prev)
            find_floor(next, now, now_floor+1);
}

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);
    graph.assign(n+1, {});
    for(int i=0; i<n-1; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    find_floor(1, -1, 0);

    int ans=0;
    for(auto& i : floor_cnt)
        ans+=min(k, i);
    
    printf("%d", ans);
}

/*
    
*/