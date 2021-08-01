// https://www.acmicpc.net/problem/1761
// 2021-08-02 03:45:32 40ms
#include<bits/stdc++.h>
using namespace std;

#define mid (s+e)/2
vector<vector<pair<int, int> > > graph;
vector<pair<int,int> > seg_tree, arr;
vector<int> seq, depth;
vector<long long> dist;

int idx=0;
void dfs(int now, int dep, long long dis)
{
    seq[now]=idx;
    dist[now]=dis;
    depth[now]=dep;
    arr[idx++]={dep, now};

    for(auto& next : graph[now])
    {
        if(seq[next.first]==-1)
        {
            dfs(next.first, dep+1, dis+next.second);
            arr[idx++]={dep,now};
        }
    }
}

pair<int,int> seg_init(int now, int s, int e)
{
    if(s==e) return seg_tree[now]=arr[s];
    return seg_tree[now]=min(seg_init(now*2, s, mid), seg_init(now*2+1, mid+1, e));
}

pair<int,int> seg_find(int now, int s, int e, int l, int r)
{
    if(r<s || e<l) return {INT32_MAX, 0};
    if(l<=s && e<=r) return seg_tree[now];
    return min(seg_find(now*2, s, mid, l, r), seg_find(now*2+1, mid+1, e, l, r));
}

pair<int,int> get_lca(int a, int b)
{
    if(seq[a]>seq[b])
        swap(a,b);
    return seg_find(1, 0, idx, seq[a], seq[b]);
}

int main(void)
{
    int n; scanf("%d", &n);

    seg_tree.assign(n*2*4, {});
    arr.assign(n*2, {});
    seq.assign(n,-1), depth.assign(n,0), dist.assign(n,0);
    graph.assign(n, vector<pair<int,int> >());

    for(int i=1; i<n; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a,&b,&c);
        graph[a-1].push_back({b-1, c});
        graph[b-1].push_back({a-1, c});
    }

    dfs(0, 0, 0);
    seg_init(1, 0, idx);

    int m; scanf("%d", &m);
    for(int i=0; i<m; i++)
    {   
        int a, b; scanf("%d%d", &a, &b);
        printf("%lld\n", dist[a-1]+dist[b-1]-2*dist[get_lca(a-1, b-1).second]);
    }
}

/*
    세그먼트 트리로 LCA 구하기
*/
