// https://www.acmicpc.net/problem/16404
// 2022-01-25 05:25:59 144ms
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class lazy_seg_tree
{
    private:
        T initial=0;
        T base=0;
        inline T f(const T& a, const T& b) 
        {
            return (a+b);
        }
        int size;
        vector<T> tree, lazy;
        T _init(const vector<T>& arr, int now, int s, int e)
        {
            if(s==e) return tree[now]=arr[s];
            else return tree[now]=f(_init(arr, now*2, s, (s+e)/2), _init(arr, now*2+1, ((s+e)/2)+1, e));
        }
        T _get(int l, int r, int now, int s, int e)
        {
            if(s>r or e<l) return base;
            else if(l<=s and e<=r) return tree[now];
            _lazy_update(now, s, e);
            return f(_get(l, r, now*2, s, (s+e)/2), _get(l, r, now*2+1, ((s+e)/2)+1, e));
        }
        T _update(int l, int r, T v, int now, int s, int e)
        {
            if(s>r or e<l) return tree[now];
            else if(l<=s and e<=r) 
            {
                lazy[now]=f(lazy[now], v*(e-s+1));
                return tree[now]=f(tree[now], v*(e-s+1));
            }
            _lazy_update(now, s, e);
            return tree[now]=f(_update(l, r, v, now*2, s, (s+e)/2), _update(l, r, v, now*2+1, ((s+e)/2)+1, e));
        }
        void _lazy_update(int now, int s, int e)
        {
            if(lazy[now])
            {
                int m=(s+e)/2;
                tree[now*2]=f(tree[now*2], lazy[now]/(e-s+1) * (m-s+1));
                lazy[now*2]=f(lazy[now*2], lazy[now]/(e-s+1) * (m-s+1));
                tree[now*2+1]=f(tree[now*2+1], lazy[now]/(e-s+1) * (e-m));
                lazy[now*2+1]=f(lazy[now*2+1], lazy[now]/(e-s+1) * (e-m));
                lazy[now]=0;
            }
        }
    public:
        lazy_seg_tree(int size)
        {
            this->size=size;
            tree.assign(size*4, initial);
            lazy.assign(size*4, 0);
        }
        T init(const vector<T>& arr, int now=0, int s=0, int e=0)
            { return now ? _init(arr, now, s, e):_init(arr, 1, 0, size-1); }
        T get(int l, int r, int now=0, int s=0, int e=0)
            { return now ? _get(l, r, now, s, e):_get(l, r, 1, 0, size-1); }
        T update(int l, int r, T value, int now=0, int s=0, int e=0)
            { return now ? _update(l, r, value, now, s, e):_update(l, r, value, 1, 0, size-1); }
};

int dfs(int now, vector<int>& start, vector<int>& end, vector<vector<int> >& graph)
{
    static int cnt=0;
    start[now]=++cnt;
    if(!graph[now].size()) return end[now]=cnt;

    int& ret=end[now];
    for(int next : graph[now])
        ret=max(ret, dfs(next, start, end, graph));
    return end[now]=ret;
}

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<vector<int> > graph(n+1);
    int trash; scanf("%d", &trash);
    for(int i=2; i<=n; i++)
    {
        int a; scanf("%d", &a);
        graph[a].push_back(i);
    }
    vector<int> start(n+1), end(n+1);
    dfs(1, start, end, graph);

    lazy_seg_tree<long long> seg(n+1);
    for(int i=0; i<m; i++)
    {
        int cmd; scanf("%d", &cmd);
        switch (cmd)
        {
        case 1:
            int a,b; scanf("%d%d", &a,&b);
            seg.update(start[a], end[a], b);
            break;
        
        default:
            int c; scanf("%d", &c);
            printf("%d\n", seg.get(start[c], start[c]));
            break;
        }
    }
}

/*
    
*/