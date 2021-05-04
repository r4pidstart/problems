
#include<bits/stdc++.h>
using namespace std;

int dfs(int start, int now, int prev, long long d, vector<vector<pair<int,int> > > &tree, map<pair<int,int>, pair<long long, int> > &dist)
{
    if(tree[now].size()==1 && tree[now][0].first==prev)
    {
        if(dist[{start,now}].first==0)
            dist[{start,now}]={d,now};
        else
            min(dist[{start,now}], {d,now});
        return 0;
    }

    for(auto it=tree[now].begin(); it!=tree[now].end(); it++)
    {
        if(it->first != prev)
            dfs(start, it->first, now, d+it->second, tree, dist);
    }
    return 0;
}
int main(void)
{
    int v; scanf("%d", &v);
    vector<vector< pair<int, int> > > tree(v+1);
    // next, distance
    for(int i=0; i<v; i++)
    {
        int a, b, d; scanf("%d", &a);
        vector<int> tmp;
        while(scanf("%d", &b))
        {
            if(b==-1) break;
            scanf("%d", &d);
            tree[a].push_back({b,d});
        }
    }

    long long ans=0;
    map<pair<int,int>, pair<long long,int> > dist;
    dfs(1, 1, 0, 0, tree, dist);
    int target, d=0; // 기준점으로부터 가장 먼 점 찾기
    for(auto it=dist.begin(); it!=dist.end(); it++)
        if(d<it->second.first)
            target=it->second.second, d=it->second.first;

    dist.clear();
    dfs(target, target, 0, 0, tree, dist);
    // 기준점으로부터 가장 먼 점으로부터 가장 먼 점과의 거리 구하기
    for(auto it=dist.begin(); it!=dist.end(); it++)
        ans=max(ans, it->second.first);
    printf("%lld", ans);
}