// https://www.acmicpc.net/problem/18227
// 2022-03-02 05:51:39 256ms
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class seg_tree
{
    private:
        T initial=0;
        T base=0;
        inline T f(const T& a, const T& b) 
        {
            return (a+b);
        }
        int size;
        vector<T> tree;
        T _init(const vector<T>& arr, int now, int s, int e)
        {
            if(s==e) return tree[now]=arr[s];
            else return tree[now]=f(_init(arr, now*2, s, (s+e)/2), _init(arr, now*2+1, ((s+e)/2)+1, e)); 
        }
        T _get(int l, int r, int now, int s, int e)
        {
            if(s>r or e<l) return base;
            else if(l<=s and e<=r) return tree[now];
            else return f(_get(l, r, now*2, s, (s+e)/2), _get(l, r, now*2+1, ((s+e)/2)+1, e));
        }
        T _update(int i, T v, int now, int s, int e)
        {
            if(!(s<=i and i<=e)) return tree[now];
            else if(s==e and s==i) return ++tree[now];
            else return tree[now]=f(_update(i, v, now*2, s, (s+e)/2), _update(i, v, now*2+1, ((s+e)/2)+1, e));
        }
    public:
        seg_tree(int size)
        {
            this->size=size;
            tree.assign(size*4, initial);
        }
        T init(const vector<T>& arr, int now=0, int s=0, int e=0)
            { return now ? _init(arr, now, s, e):_init(arr, 1, 0, size-1); }
        T get(int l, int r, int now=0, int s=0, int e=0)
            { return now ? _get(l, r, now, s, e):_get(l, r, 1, 0, size-1); }
        T update(int index, T value, int now=0, int s=0, int e=0)
            { return now ? _update(index, value, now, s, e):_update(index, value, 1, 0, size-1); }
};

int dfs(int now, int prev, int dep, 
    vector<vector<int> >& graph, vector<int> &depth, vector<int>& end, vector<int>& idx)
{
    static int cnt=0;
    idx[now]=++cnt; 
    depth[now]=dep;

    int end_idx=cnt;
    for(auto next : graph[now])
        if(next != prev)
            end_idx=max(end_idx, dfs(next, now, dep+1, graph, depth, end, idx));
    return end[now]=end_idx;
}

int main(void)
{
    int n,c; scanf("%d%d", &n, &c);
    vector<vector<int> > graph(n+1);
    for(int i=0; i<n-1; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> depth(n+1), end(n+1), idx(n+1);
    dfs(c, 0, 1, graph, depth, end, idx);
    seg_tree<long long> seg(n+1);
    
    int q; scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        if(a==1)
            seg.update(idx[b], 0);
        else
            printf("%lld\n", depth[b]*seg.get(idx[b], end[b]));
    }
}

/*
    
*/