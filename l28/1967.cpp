// https://www.acmicpc.net/problem/1967
// 2021-05-03 20:51:55 4ms
#include<bits/stdc++.h>
using namespace std;

int dfs(int now, int prev, int d, vector<vector<pair<int,int> > > &tree)
{
    if(tree[now].size()==1 && tree[now][0].first==prev)
        return d;
    else
    {
        int ret=0;
        for(auto it=tree[now].begin(); it!=tree[now].end(); it++)
            if(it->first != prev)
                ret=max(ret, dfs(it->first, now, d+it->second, tree));
        return ret;
    }
}

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> distance(n+1, 0);
    vector<vector<pair<int,int> > > tree(n+1);
    pair<int,int> max_distance={0,0}; // dist, point
    for(int i=1; i<n; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        distance[b]=distance[a]+c;
        max_distance=max(max_distance, {distance[b], b});
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }
    printf("%d",dfs(max_distance.second, 0, 0, tree));    
}