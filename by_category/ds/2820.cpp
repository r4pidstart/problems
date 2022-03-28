// https://www.acmicpc.net/problem/2820
// 2022-03-29 02:50:41 808ms
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


void dfs(int now, vector<vector<int> >& graph, vector<pair<int,int> >& ett)
{
    static int cnt=0;
    ett[now].first=++cnt;

    for(auto next : graph[now])
        dfs(next, graph, ett);

    ett[now].second=cnt;
}

int main(void)
{
    cin.tie(NULL)->sync_with_stdio(false);
    int n,m; cin >> n >> m;
    lazy_seg_tree<long long> seg(n+1);
    vector<int> init_wage(n+1);
    cin >> init_wage[1];
    vector<vector<int> > graph(n+1);
    for(int i=2; i<=n; i++)
    {
        int a,b; cin >> a >> b;
        init_wage[i]=a;
        graph[b].push_back(i);
    }

    vector<pair<int,int> > ett(n+1);
    dfs(1, graph, ett);

    for(int i=1; i<=n; i++)
        seg.update(ett[i].first, ett[i].first, init_wage[i]);

    for(int i=0; i<m; i++)
    {
        char c; cin >> c;
        if(c=='p')
        {
            int a,x; cin >> a >> x;
            seg.update(ett[a].first+1, ett[a].second, x);
        }
        else
        {
            int a; cin >> a;
            cout << seg.get(ett[a].first, ett[a].first) << '\n';
        }
    }
}

/*
    
*/